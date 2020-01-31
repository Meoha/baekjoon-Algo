#include <iostream>

using namespace std;

int fibo[41][2];
int N;

void fibonacci(int n) {

	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;

	for (int i = 2; i <= 40; i++) {

		fibo[i][0] = fibo[i - 2][0] + fibo[i - 1][0];
		fibo[i][1] = fibo[i - 2][1] + fibo[i - 1][1];

	}

	return;

}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> N;

		fibonacci(N);

		cout << fibo[N][0] << ' ' << fibo[N][1] << '\n';

	}

	return 0;
}