#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct man {

	int a;
	int b;
	int life;

};

int N;
int M;
int board[1000][1000];
int visited[1000][1000][2];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<man> q;
int ans = 1000001;
bool flag = false;

void sol() {
	
	while (!q.empty()) {

		int x = q.front().a;
		int y = q.front().b;
		int l = q.front().life;

		q.pop();

		if (x == M - 1 && y == N - 1) {

			flag = true;

			if (ans > visited[x][y][l]) {

				ans = visited[x][y][l];

			}

			break;
		}

		for (int i = 0; i < 4; i++) {

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny][l]) {

				if (board[nx][ny] == 0) {

					q.push({ nx, ny, l });
					visited[nx][ny][l] = visited[x][y][l] + 1;

				}
				else if(board[nx][ny] == 1 && l == 1) {

					q.push({ nx, ny, 0 });
					visited[nx][ny][0] = visited[x][y][l] + 1;

				}

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int n = 0; n < N; n++) {

		string s;
		cin >> s;

		for (int m = 0; m < M; m++) {

			board[m][n] = s[m] - '0';

		}
	}

	q.push({ 0, 0, 1 });
	visited[0][0][1] = 1;

	sol();

	if (!flag) {

		cout << -1 << '\n';

	}
	else {

		cout << ans << '\n';

	}

	return 0;
}