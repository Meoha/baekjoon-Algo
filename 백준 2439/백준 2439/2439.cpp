#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;

	for (int n = 1; n <= N; n++) {

		for (int j = 1; j <= N - n; j++) {

			cout << " ";
		
		}

		for (int i = 1; i <= n; i++) {

			cout << "*";

		}

		cout << '\n';

	}

	return 0;
}