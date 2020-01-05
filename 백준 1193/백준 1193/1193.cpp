#include <iostream>

using namespace std;

int main() {

	int X;

	cin >> X;

	int i = 0;
	int sum = 0;

	if (X == 1) {

		cout << "1/1" << '\n';

	}
	else {

		while (sum < X) {

			i++;

			sum = sum + i;

		}

		if (i % 2 == 0) {

			int j = sum - X;

			cout << i - j << "/" << 1 + j << '\n';

		}
		else {

			int j = sum - X;

			cout << 1 + j << "/" << i - j << '\n';

		}

	}

	return 0;
}