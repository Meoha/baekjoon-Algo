#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		int H, W, N;

		cin >> H >> W >> N;

		if (N % H == 0) {

			if (N / H < 10) {

				cout << H << 0 << N / H << '\n';

			}
			else {

				cout << H << N / H << '\n';

			}

		}
		else {

			if (N / H + 1 < 10) {

				cout << N % H << 0 << N / H + 1 << '\n';

			}
			else {

				cout << N % H << N / H + 1 << '\n';

			}

		}

	}

	return 0;
}