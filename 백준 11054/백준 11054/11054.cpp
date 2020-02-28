#include <iostream>
#include <algorithm>

using namespace std;

int N; //수열의 길이
int arr[1000]; //수열의 정보
int dp[1000]; //LIS;
int ans;

void sol() {

	//증가하는 부분
	for (int i = 0; i < N; i++) {

		dp[i] = 1;
		
		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {

				dp[i] = dp[j] + 1;

			}

		}

	}

	//감소하는 부분
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < i; j++) {

			if (arr[i] < arr[j] && dp[i] < dp[j] + 1) {

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