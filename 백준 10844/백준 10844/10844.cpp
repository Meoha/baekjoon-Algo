#include <iostream>

using namespace std;

int N;
int dp[100][10];
int ans;

void sol() {

	for (int i = 1; i <= 9; i++) {

		dp[0][i] = 1;

	}

	for (int i = 1; i < N; i++) {

		for (int j = 0; j < 10; j++) {

			if (j == 0) {

				dp[i][0] = (dp[i - 1][1]) % 1000000000;

			}
			else if (j == 9) {

				dp[i][9] = (dp[i - 1][8]) % 1000000000;

			}
			else{

				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;

			}

		}

	}

	for (int i = 0; i <= 9; i++) {

		ans = (ans + dp[N - 1][i]) % 1000000000;

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	sol();

	cout << ans << '\n';

	return 0;
}