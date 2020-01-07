#include <iostream>

using namespace std;

int main() {

	int N;

	cin >> N;

	int arr[100] = { 0 };
	int ans = 0;

	for (int n = 0; n < N; n++) {

		cin >> arr[n];

		if (arr[n] != 1) {
			
			bool flag = true;

			for (int i = 2; i < arr[n] / 2 + 1; i++) {

				if (arr[n] % i == 0) {

					flag = false;

					break;
				}
			
			}

			if (flag) {

				ans++;

			}
		}
	}

	cout << ans << '\n';

	return 0;
}