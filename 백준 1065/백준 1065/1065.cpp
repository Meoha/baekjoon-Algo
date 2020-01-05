#include <iostream>

using namespace std;

int sol(int n) {

	int result = 0;

	if (n < 100) {

		result = n;

	}
	else if (n >= 100 && n <= 1000) {

		result = 99;

		if (n == 1000) {
			
			n = 999;
		}

		for (int i = 100; i <= n; i++) {

			int a = i % 10;
			int temp = i / 10;
			int b = temp % 10;
			int c = temp / 10;

			if (c - b == b - a) {

				result++;

			}

		}

	}

	return result;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;

	int ans = sol(N);

	cout << ans << '\n';

	return 0;
}