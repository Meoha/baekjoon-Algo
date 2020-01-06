#include <iostream>	

using namespace std;

int main() {

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		int k, n;

		cin >> k >> n;

		int arr[15][15] = { 0 };

		for (int i = 1; i < 15; i++) {

			arr[0][i] = i;

		}

		for (int i = 1; i < 15; i++) {

			for (int j = 1; j < 15; j++) {

				for (int c = 1; c <= j; c++) {

					arr[i][j] = arr[i][j] + arr[i - 1][c];

				}

			}

		}

		cout << arr[k][n] << '\n';

	}

	return 0;
}