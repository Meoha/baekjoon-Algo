#include <iostream>

using namespace std;

int N; //동전의 종류의 수
int K; //합
int coin[10];

int sol() {

	int sum = K;
	int n = 0;

	for (int i = N - 1; i >= 0; i--) {

		if (sum == 0) {

			break;

		}
		else {

			if (sum >= coin[i]) {

				n = n + sum / coin[i];
				sum = sum % coin[i];

			}

		}

	}

	return n;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {

		cin >> coin[i];

	}

	int ans = sol();

	cout << ans << '\n';

	return 0;
}