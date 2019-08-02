#include <iostream>
#include <vector>

using namespace std;

int T; //테스트 케이스 수
int N; //지도의 한 변의 길이
int K; //최대 공사 가능 깊이
int map[8][8];
int visited[8][8];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;
vector <pair<int, int>> V;

//가장 높은 봉우리 찾는 함수
void find(int height) {

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {

			if (map[m][n] == height) {
				V.push_back(make_pair(m, n));
			}
		}
	}
}

//등산로 찾기
void dfs(int m, int n, int length) {

	if (length == 1) {
		visited[m][n] = length;
	}

	for (int i = 0; i < 4; i++) {

		int nx = m + dx[i];
		int ny = n + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {

			if (map[nx][ny] < map[m][n]) {
				if (length + 1 > visited[nx][ny]) {
					visited[nx][ny] = length + 1;
					dfs(nx, ny, length + 1);
				}
			}
		}
	}
}


int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> N >> K;

		int high_Max = 0;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {
				int temp;

				cin >> temp;

				if (high_Max < temp) {
					high_Max = temp;
				}
				map[m][n] = temp;
			}
		}

		find(high_Max);

		for (int v = 0; v < V.size(); v++) {
			int x = V[v].first;
			int y = V[v].second;


			for (int n = 0; n < N; n++) {
				for (int m = 0; m < N; m++) {
					for (int k = 1; k <= K; k++) {
						map[m][n] -= k;

						dfs(x, y, 1);

						for (int n = 0; n < N; n++) {
							for (int m = 0; m < N; m++) {
								if (ans < visited[m][n]) {
									ans = visited[m][n];
								}

								visited[m][n] = 0;
							}
						}

						map[m][n] += k;
					}
				}
			}
		}

		cout << '#' << t << ' ' << ans << endl;

		ans = 0;

		for (int n = 0; n < 8; n++) {
			for (int m = 0; m < 8; m++) {

				map[m][n] = 0;
				visited[m][n] = 0;
			}
		}

		V.clear();
	}

	return 0;
}