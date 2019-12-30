#include <iostream>

using namespace std;

int main() {

	int N;

	cin >> N;

	int arr[1000000] = { 0 };

	for (int i = 0; i < N; i++) {

		cin >> arr[i];

	}

	int MAX = -1000000;
	int MIN = 1000000;

	for (int i = 0; i < N; i++) {

		if (MAX < arr[i]) {

			MAX = arr[i];

		}

		if (MIN > arr[i]) {

			MIN = arr[i];

		}

	}

	cout << MIN << " " << MAX << '\n';

	return 0;
}