#include <iostream>

using namespace std;

int N;
int board[20][20];
int ans = 99;
bool visited[20];

void sol(int last, int member) {

	if (member == N / 2) {

		int start = 0;
		int link = 0;

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {

				if (visited[i] && visited[j]) {

					start = start + board[i][j] + board[j][i];

				}
				else if (!visited[i] && !visited[j]) {

					link = link + board[i][j] + board[j][i];

				}
			}
		}

		int result = start - link;

		if (result < 0) {

			result = -result;

		}

		if (ans > result) {

			ans = result;

		}

		return;
	}
	else {

		if (last < N) {

			visited[last] = true;
			sol(last + 1, member + 1);
			visited[last] = false;
			sol(last + 1, member);

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> board[i][j];

		}
	}

	//sol
	sol(0, 0);

	cout << ans << '\n';

	return 0;
}