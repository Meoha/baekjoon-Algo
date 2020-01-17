#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;

	int i = 0;
	bool flag = false;
	int ans = 0;

	while (N - i >= 1) {

		int temp = N - i;
		int sum = temp;

		while (1) {

			if (temp / 10 == 0 && temp % 10 == 0) {

				break;

			}

			sum = sum + temp % 10;
			temp = temp / 10;

		}

		if (sum == N) {

			flag = true;
			ans = i;

		}

		i++;
	}

	if (flag) {

		cout << N - ans << '\n';

	}
	else {

		cout << 0 << '\n';

	}

	return 0;
}