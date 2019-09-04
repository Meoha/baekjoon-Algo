#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int N; //세로길이
int M; //가로길이
int map[101][101];
int visited[101][101];
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;

void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && map[nx][ny] == 1 && visited[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[x][y] + 1;

				//먼저 도착하면 그만
				if (nx == M && ny == N) {
					
					return;
				}
			}

		}

	}

}

int main() {

	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			int temp = 0;

			scanf("%1d", &temp);

			map[m][n] = temp;
		}
	}

	q.push({ 1, 1 });
	visited[1][1] = 1;

	bfs();

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {

			if (ans < visited[m][n]) {
				ans = visited[m][n];
			}
		}
	}

	cout << ans << endl;

	return 0;
}