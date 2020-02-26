#include <iostream>
#include <algorithm>

using namespace std;

int N; //포도주 잔의 개수
int arr[10001]; //포도주 정보
int dp[10000][3];

void sol() {

	dp[1][0] = 0;
	dp[1][1] = arr[1];
	dp[1][2] = 0;
	dp[2][0] = dp[1][1];
	dp[2][1] = dp[1][1] + arr[2];
	dp[2][2] = dp[1][0] + arr[2];

	for (int i = 3; i <= N + 1; i++) {

		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = max(dp[i - 1][0] + arr[i], dp[i - 1][2] + arr[i]);
		dp[i][2] = dp[i - 1][0] + arr[i];

		//cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';

	}

	return;
}


int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {

		cin >> arr[i];

	}

	//sol
	sol();

	cout << dp[N + 1][0] << '\n';

	return 0;
}