#include <iostream>
#include <algorithm>

using namespace std;

int N; //계단의 개수
int stair[302]; //계단에 쓰여 있는 점수
int dp[302][3];

void sol() {

	dp[1][0] = 0;
	dp[1][1] = stair[1];
	dp[1][2] = 0;
	dp[2][0] = max(dp[1][1], dp[1][2]);
	dp[2][1] = dp[1][1] + stair[2];
	dp[2][2] = dp[1][0] + stair[2];
	dp[3][0] = max(dp[2][1], dp[2][2]);
	dp[3][1] = dp[2][2] + stair[3];
	dp[3][2] = dp[1][1] + stair[3];
	
	for (int i = 4; i <= N + 1; i++) {

		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = stair[i] + dp[i - 1][2];
		dp[i][2] = max(stair[i] + dp[i - 2][1], stair[i] + dp[i - 2][2]);

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {

		cin >> stair[i];

	}

	//dp

	sol();

	cout << dp[N + 1][0] << '\n';

	return 0;
}