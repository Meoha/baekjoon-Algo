#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N;
int map[20][20];
int ans;
int start_x;
int start_y;

void dfs(int m, int n, int length, int dir, int* temp_map) {

	if (m == start_x && n == start_y && dir == 5) {
		ans = max(ans, length);
		return;
	}

	temp_map[map[m][n]] = 1;

	if (dir == 1) {
		int nx = m - 1;
		int ny = n + 1;

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {

			if (temp_map[map[nx][ny]] == 0) {
				temp_map[map[nx][ny]] = 1;
				dfs(nx, ny, length + 1, 1, temp_map);
				temp_map[map[nx][ny]] = 0;
				dfs(nx, ny, length + 1, 2, temp_map);
				temp_map[map[nx][ny]] = 0;
			}
		}
	}
	else if (dir == 2) {
		int nx = m + 1;
		int ny = n + 1;

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (temp_map[map[nx][ny]] == 0) {
				temp_map[map[nx][ny]] = 1;
				dfs(nx, ny, length + 1, 2, temp_map);
				temp_map[map[nx][ny]] = 0;
				dfs(nx, ny, length + 1, 3, temp_map);
				temp_map[map[nx][ny]] = 0;
			}

		}
	}
	else if (dir == 3) {
		int nx = m + 1;
		int ny = n - 1;

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (temp_map[map[nx][ny]] == 0) {
				temp_map[map[nx][ny]] = 1;
				dfs(nx, ny, length + 1, 3, temp_map);
				temp_map[map[nx][ny]] = 0;
				dfs(nx, ny, length + 1, 4, temp_map);
				temp_map[map[nx][ny]] = 0;
			}
		}
	}
	else if (dir == 4) {
		int nx = m - 1;
		int ny = n - 1;

		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (temp_map[map[nx][ny]] == 0) {
				temp_map[map[nx][ny]] = 1;
				dfs(nx, ny, length + 1, 4, temp_map);
				temp_map[map[nx][ny]] = 0;
			}

			if (nx == start_x && ny == start_y) {
				dfs(nx, ny, length, 5, temp_map);
			}

		}
	}


	temp_map[map[m][n]] = 0;
}


int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> N;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {

				int temp;

				cin >> temp;

				map[m][n] = temp;

			}
		}


		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {
				int temp_map[101] = {};

				start_x = m;
				start_y = n;

				dfs(m, n, 1, 1, temp_map);
			}
		}

		if (ans == 0) {
			ans = -1;
		}

		cout << '#' << t << ' ' << ans << endl;

		ans = 0;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {

				map[m][n] = 0;

			}
		}
	}

	return 0;
}