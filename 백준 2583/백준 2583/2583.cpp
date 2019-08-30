#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M; //세로길이
int N; //가로 길이
int K; //직사각형의 개수
int map[101][101];
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> ans;
queue<pair<int, int>> q;

void bfs() {

	int scale = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && map[nx][ny] == 0) {

				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				scale++;
			}
		}
	}

	ans.push_back(scale);
}


int main() {

	cin >> M >> N >> K;


	for (int k = 0; k < K; k++) {
		int x1, y1, x2, y2 = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++) {
			for (int i = x1; i < x2; i++) {
				map[i][j] = 1;
			}
		}

	}

	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {

			if (map[n][m] == 0 && !visited[n][m]) {
				q.push(make_pair(n, m));
				visited[n][m] = true;
				bfs();
			}
		}
	}

	cout << ans.size() << endl;

	//오름차순으로 정렬
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	
	cout << endl;

	return 0;
}