#include <iostream>

using namespace std;

int N;
int M;
int K;
int arr[10][10];
bool visited[10][10];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int ans = -987654321;

void sol(int n, int m, bool visited[10][10], int result, int select) {

	if (select == K) {

		if (ans < result) {

			ans = result;

			return;

		}

	}
	else {

		for (int i = n; i < N; i++) {

			int start = 0;

			if (i == n) {

				start = m;

			}

			for (int j = start; j < M; j++) {

				if (!visited[j][i]) {

					bool flag = true;

					for (int d = 0; d < 4; d++) {

						int nx = j + dir[d][0];
						int ny = i + dir[d][1];

						if (nx >= 0 && nx < M && ny >= 0 && ny < N) {

							if (visited[nx][ny]) {

								flag = false;

								break;

							}

						}

					}

					if (flag) {

						visited[j][i] = true;
						sol(i, j, visited, result + arr[j][i], select + 1);
						visited[j][i] = false;

					}

				}

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int n = 0; n < N; n++) {

		for (int m = 0; m < M; m++) {

			cin >> arr[m][n];

		}

	}

	bool visited[10][10] = { false };

	sol(0, 0, visited, 0, 0);

	cout << ans << '\n';

	return 0;
}