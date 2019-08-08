#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T; //테스트 케이스 수
int N; //수영장의 크기
int map[15][15];
int visited[15][15];
int A, B; //시작 위치
int C, D; //도착 위치
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans = -1;
bool flag = false;
vector<pair<int, int>> v;
queue<pair<int, pair<int, int>>> q;

void bfs() {


	//visited[b][a] = 1;

	while (!q.empty()) {

		int time = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x == D && y == C) {

			ans = time;
			flag = true;

			break;
		}

		if (time % 3 == 2) {

			//토네이도가 사라질때
			for (int i = 0; i < v.size(); i++) {
				int vx = v[i].first;
				int vy = v[i].second;

				map[vx][vy] = 0;
			}

		}
		else {
			//토네이도가 있을때

			for (int i = 0; i < v.size(); i++) {
				int vx = v[i].first;
				int vy = v[i].second;

				map[vx][vy] = 2;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] != 1 && !visited[nx][ny]) {
				if (map[nx][ny] == 0) {
					visited[nx][ny] = 1;
					q.push(make_pair(time + 1, make_pair(nx, ny)));
				}
				else if (map[nx][ny] == 2) {
					q.push(make_pair(time + 1, make_pair(x, y)));
				}
			}
		}

	}
}


int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				int temp;

				cin >> temp;

				map[j][i] = temp;

				//토네이도가 존재하는 위치
				if (temp == 2) {
					v.push_back(make_pair(j, i));
				}

			}
		}

		cin >> A >> B;

		q.push(make_pair(0, make_pair(B, A)));
		visited[B][A] = 1;

		cin >> C >> D;

		//길찾기
		
		bfs();

		
		if (flag == false) {
			ans = -1;
		}
		

		cout << "#" << t << " " << ans << endl;

		ans = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[j][i] = 0;
				visited[j][i] = 0;
			}
		}

		v.clear();

		while (!q.empty()) {
			q.pop();
		}
		
	}




	return 0;
}