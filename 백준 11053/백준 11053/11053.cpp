#include <iostream>
#include <algorithm>

using namespace std;

int N; //수열의 크기
int arr[1000]; //수열의 정보
int dp[1000];
int ans;

void sol() {

	dp[0] = 1;

	for (int i = 1; i < N; i++) {

		if (dp[i] == 0) dp[i] = 1;

		for (int j = 0; j < i; j++) {

			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {

				dp[i] = dp[j] + 1;

			}

		}
	}

	for (int i = 0; i < N; i++) {

		ans = max(ans, dp[i]);

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];

	}

	//sol
	sol();

	cout << ans << '\n';

	return 0;
}