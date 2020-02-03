#include <iostream>
#include <algorithm>

using namespace std;

int N;
int tri[501][501];
int dp[501][501];
int ans;

void sol() {

	dp[1][1] = tri[1][1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {

			dp[i][j] = tri[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);

		}
	}

	for (int i = 1; i <= N; i++) {

		ans = max(ans, dp[N][i]);

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {

			cin >> tri[i][j];

		}
	}

	sol();

	cout << ans << '\n';

	return 0;
}