#include <iostream>

using namespace std;

int main() {

	int input[3] = { 0 };
	int arr[10] = { 0 };
	int result = 1;

	for (int i = 0; i < 3; i++) {

		cin >> input[i];

		result = result * input[i];
	}

	arr[result % 10]++;

	while (result / 10 != 0){

		result = result / 10;
		arr[result % 10]++;

	}

	for (int j = 0; j < 10; j++) {

		cout << arr[j] << '\n';

	}

	return 0;
}