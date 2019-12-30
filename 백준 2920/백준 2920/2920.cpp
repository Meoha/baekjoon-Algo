#include <iostream>

using namespace std;

int main() {

	int arr[8] = { 0 };

	for (int i = 0; i < 8; i++) {

		cin >> arr[i];

	}

	if (arr[0] == 1) {

		for (int i = 1; i < 8; i++) {

			if (arr[i] != arr[i - 1] + 1) {
				
				cout << "mixed" << '\n';
				return 0;
			
			}

		}

		cout << "ascending" << '\n';

	}
	else if (arr[0] == 8) {

		for (int i = 1; i < 8; i++) {

			if (arr[i] != arr[i - 1] - 1) {

				cout << "mixed" << '\n';
				return 0;

			}

		}

		cout << "descending" << '\n';

	}
	else {

		cout << "mixed" << '\n';

	}


	return 0;
}