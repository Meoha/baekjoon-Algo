#include <iostream>
#include <algorithm>

using namespace std;

int N;
int rgb[1000][3];
int dp[1000][3];
int ans = 1000000;

void sol() {

	dp[0][0] = rgb[0][0];
	dp[0][1] = rgb[0][1];
	dp[0][2] = rgb[0][2];

	for (int i = 1; i < N; i++) {

		dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);

	}

	ans = min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 3; i++) {

			cin >> rgb[n][i];

		}
	}

	sol();

	cout << ans << '\n';

	return 0;
}