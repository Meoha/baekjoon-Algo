#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B;

	while (1) {

		cin >> A >> B;

		if (A == 0 && B == 0) {

			return 0;

		}
		else {

			cout << A + B << '\n';

		}

	}

	return 0;
}