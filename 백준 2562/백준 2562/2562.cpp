#include <iostream>

using namespace std;

int main() {

	int arr[9] = { 0 };

	for (int i = 0; i < 9; i++) {

		cin >> arr[i];

	}

	int index = 0;
	int MAX = 0;

	for (int i = 0; i < 9; i++) {

		if (MAX < arr[i]) {

			MAX = arr[i];
			index = i + 1;

		}

	}

	cout << MAX << "\n";
	cout << index << '\n';

	return 0;
}