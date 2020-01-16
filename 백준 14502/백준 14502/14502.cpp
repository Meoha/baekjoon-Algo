#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; //지도의 세로 크기
int M; //지도의 가로 크기
int board[8][8]; //지도 정보
int temp_board[8][8];
bool visited[8][8]; //방문 배열
int ans; //안전 영역의 최대 크기
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q; //바이러스 큐
vector<pair<int, int>> v; //처음 바이러스 위치
vector<pair<int, int>> wall; //벽

void init() {

	for (int i = 0; i < v.size(); i++) {

		q.push(make_pair(v[i].first, v[i].second));

	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			temp_board[n][m] = board[n][m];
			visited[n][m] = false;

		}
	}

	return;
}

void virus() {

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		//바이러스가 퍼짐
		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx]) {

				visited[ny][nx] = true;

				if (temp_board[ny][nx] == 0) {

					temp_board[ny][nx] = 2;
					q.push(make_pair(nx, ny));

				}
				
			}

		}

	}

	int result = 0;
	
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
		
			if(temp_board[n][m] == 0)
				result++;

		}
	}

	if (ans < result) {

		ans = result;

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {

			cin >> board[n][m];

			if (board[n][m] == 2) {

				v.push_back(make_pair(m, n));

			}
			else if (board[n][m] == 0) {

				wall.push_back(make_pair(m, n));

			}

		}
	}

	//sol

	for (int i = 0; i < wall.size() - 2; i++) {
		for (int j = i + 1; j < wall.size() - 1; j++) {
			for (int k = j + 1; k < wall.size(); k++) {

				init();

				temp_board[wall[i].second][wall[i].first] = 1;
				temp_board[wall[j].second][wall[j].first] = 1;
				temp_board[wall[k].second][wall[k].first] = 1;

				virus();

			}
		}
	}

	//출력
	cout << ans << '\n';




	return 0;
}