#include <iostream>

using namespace std;

int N;
int num[11];
int MIN = 1000000000;
int MAX = -1000000000;

void sol(int n, int result, int calc[4]) {

	//종료 조건
	if (n == N - 1) {

		if (MAX < result) {

			MAX = result;

		}
		
		if (MIN > result) {

			MIN = result;

		}

		return;
	}
	else {

		for (int i = 0; i < 4; i++) {

			if (calc[i] != 0) {

				calc[i]--;

				if (i == 0) {

					sol(n + 1, result + num[n + 1], calc);

				}
				else if (i == 1) {

					sol(n + 1, result - num[n + 1], calc);

				}
				else if (i == 2) {

					sol(n + 1, result * num[n + 1], calc);

				}
				else if (i == 3) {

					sol(n + 1, result / num[n + 1], calc);

				}

				calc[i]++;

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		
		cin >> num[i];
	
	}

	int calc[4] = { 0 };

	for (int i = 0; i < 4; i++) {

		cin >> calc[i];

	}

	//sol
	sol(0, num[0], calc);

	cout << MAX << '\n';
	cout << MIN << '\n';

	return 0;
}