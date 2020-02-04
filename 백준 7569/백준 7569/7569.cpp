#include <iostream>
#include <queue>

using namespace std;

struct tomato {

	int x;
	int y;
	int z;

};

int M; //상자의 가로 칸 수
int N; //상자의 세로 칸 수
int H; //상자의 높이 개수
int box[100][100][100]; //상자에 담긴 토마토 정보
int visited[100][100][100]; //방문 배열
queue<tomato> q;
int dir[6][3][1] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
int ripe;

void sol() {

	while (!q.empty()) {

		int m = q.front().x;
		int n = q.front().y;
		int h = q.front().z;

		q.pop();

		for (int i = 0; i < 6; i++) {

			int nx = m + dir[i][0][0];
			int ny = n + dir[i][1][0];
			int nz = h + dir[i][2][0];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H && !visited[nx][ny][nz]) {

				if (box[nx][ny][nz] == 0) {

					q.push({ nx, ny, nz });
					ripe--;
					visited[nx][ny][nz] = visited[m][n][h] + 1;
				}

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N >> H;

	bool flag = false;

	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {

				cin >> box[m][n][h];

				if (box[m][n][h] == 1) {

					q.push({ m, n, h });
					visited[m][n][h] = 1;

				}
				else if (box[m][n][h] == 0) {

					flag = true;
					ripe++;

				}
			}
		}
	}

	//sol
	if (flag) {

		sol();

		if (!ripe) {

			int ans = 0;

			for (int h = 0; h < H; h++) {
				for (int n = 0; n < N; n++) {
					for (int m = 0; m < M; m++) {

						if (ans < visited[m][n][h]) {

							ans = visited[m][n][h];

						}
					}
				}
			}

			//출력
			cout << ans - 1 << '\n';

		}
		else {

			cout << -1 << '\n';

		}

	}
	else {

		cout << 0 << '\n';

	}

	return 0;
}