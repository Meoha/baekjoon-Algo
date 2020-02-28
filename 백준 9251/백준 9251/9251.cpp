#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s1;
string s2;
int dp[1000][1000];

int sol(int len1, int len2) {

	if (len1 < 0 || len2 < 0) {

		return 0;
	}

	if (dp[len1][len2] != -1) {

		return dp[len1][len2];
	}
	else {

		if (s1[len1] == s2[len2]) {

			dp[len1][len2] = sol(len1 - 1, len2 - 1) + 1;

		}
		else {

			dp[len1][len2] = max(sol(len1 - 1, len2), sol(len1, len2 - 1));

		}

	}

	return dp[len1][len2];
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s1 >> s2;

	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {

			dp[i][j] = -1;

		}
	}

	//sol
	int ans = sol(s1.length() - 1, s2.length() - 1);

	cout << ans << '\n';

	return 0;
}