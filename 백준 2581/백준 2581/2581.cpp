#include <iostream>

using namespace std;

int main() {

	int M, N;

	cin >> M >> N;

	int MIN = 10000;
	int sum = 0;

	for (int i = M; i <= N; i++) {

		if (i != 1) {

			bool flag = true;

			for (int j = 2; j < i / 2 + 1; j++) {

				if (i % j == 0) {

					flag = false;

					break;
				}
			}

			if (flag) {

				sum = sum + i;

				if (MIN > i) {

					MIN = i;

				}

			}

		}
	}

	if (sum == 0) {

		cout << -1 << '\n';

	}
	else {

		cout << sum << '\n';
		cout << MIN << '\n';

	}

	return 0;
}