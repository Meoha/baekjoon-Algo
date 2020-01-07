#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {

		int n;

		cin >> n;

		if (n == 0) {

			break;
		}
		else {

			int cnt = 0;

			for (int i = n + 1; i <= 2 * n; i++) {

				if (i != 1) {

					bool flag = true;

					for (int j = 2; j * j <= i; j++) {

						if (i % j == 0) {

							flag = false;

							break;
						}
					}

					if (flag) {

						cnt++;

					}

				}

			}

			cout << cnt << '\n';

		}
	}

	return 0;
}