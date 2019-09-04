#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N; //보물지도의 세로의 크기
int M; //보물지도의 가로의 크기
int map[50][50]; //보물지도
int visited[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;
queue<pair<int, int>> q;

void bfs() {

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}

	}
	
	return;
}

void cleaner() {

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			
			if (ans < visited[m][n]) {
				ans = visited[m][n] - 1;
			}

			visited[m][n] = false;
		}
	}

	return;
}

int main() {

	cin >> N >> M;

	for (int n = 0; n < N; n++) {

		string temp;

		cin >> temp;

		for (int m = 0; m < M; m++) {

			if (temp[m] == 'L') {
				map[m][n] = 1;
			}
			else if(temp[m] == 'W') {
				map[m][n] = 0;
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
		
			if (map[m][n] == 1) {

				visited[m][n] = 1;
				q.push(make_pair(m, n));
				
				bfs();

				cleaner();
			}
		}
	}

	cout << ans << endl;


	return 0;
}