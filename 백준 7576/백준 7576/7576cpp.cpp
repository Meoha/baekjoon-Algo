#include <iostream>
#include <queue>

using namespace std;

int M; //상자의 가로 칸의 수
int N; //상자의 세로 칸의 수
int map[1001][1001];
int ripe; //익어야하는 토마토의 수
int day; //토마토가 모두 익을 때까지의 최소 날짜
queue<pair<int, int>> q;
int visited[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[nx][ny] == 0 && visited[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[x][y] + 1;
				ripe--;
			}
		}
	}

}

int main() {

	cin >> M >> N;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			int temp = 0;

			cin >> temp;

			map[m][n] = temp;

			if (temp == 0) {
				ripe++;
			}
			else if (temp == 1) {
				q.push(make_pair(m, n));
				visited[m][n] = 1;
			}
		}
	}

	if (ripe == 0) {
		cout << 0 << endl;

		return 0;
	}

	bfs();

	if (ripe == 0) {

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (visited[m][n] > day) {
					day = visited[m][n] - 1;
				}
			}
		}

		cout << day << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}