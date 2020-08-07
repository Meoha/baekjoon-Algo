#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sum = 0;

	for (int i = 0; i < 5; i++) {

		int score = 0;

		cin >> score;

		if (score < 40) {

			score = 40;

		}

		sum += score;

	}

	cout << sum / 5 << '\n';

	return 0;
}