#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;

	int i = 0;
	int num = 666;

	while (i <= N - 1) {

		int temp = num;

		while (temp >= 666) {

			if (temp % 1000 == 666) {

				i++;

				break;
			}

			temp = temp / 10;

		}

		num++;

	}

	cout << num - 1 << '\n';

	return 0;
}