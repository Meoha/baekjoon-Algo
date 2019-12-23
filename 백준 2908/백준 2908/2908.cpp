#include <iostream>
#include <string>

using namespace std;

int main() {

	int arr[2] = {0};

	for (int i = 0; i < 2; i++) {
		cin >> arr[i];
	}

	string temp1;

	for (int i = 0; i < 2; i++) {

		string temp2 = to_string(arr[i]);
		arr[i] = 0;

		for (int j = temp2.length() - 1; j >= 0; j--) {
			arr[i] = arr[i] * 10 + (temp2[j] - '0');
		}

	}

	if (arr[0] < arr[1]) {
		cout << arr[1] << '\n';
	}
	else {
		cout << arr[0] << '\n';
	}


	return 0;
}