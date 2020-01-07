#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;

	cin >> M >> N;

	for (int i = M; i <= N; i++) {

		if (i != 1) {

			bool flag = true;

			for (int j = 2; j * j <= i; j++) {

				if (i % j == 0) {

					flag = false;

					break;
				}
			}

			if (flag) {

				cout << i << '\n';
			}

		}
	}

	return 0;
}