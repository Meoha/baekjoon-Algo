#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;

	bool arr[10000] = { false };

	for (int j = 2; j < 10000; j++) {

		bool flag = true;

		for (int i = 2; i * i <= j; i++) {

			if (j % i == 0) {

				flag = false;

				break;
			}

		}

		if (flag) {

			arr[j] = true;

		}

	}

	for (int t = 0; t < T; t++) {

		int n;

		cin >> n;

		int a, b = 0;

		for (int i = n / 2; i >= 2; i--) {

			if (arr[i] && arr[n - i]) {

				a = i;
				b = n - i;

				break;

			}

		}

		cout << a << ' ' << b << '\n';

	}

	return 0;
}