#include <iostream>

using namespace std;

int main() {

	int arr[10] = { 0 };
	bool check[42] = { false };

	for (int i = 0; i < 10; i++) {

		cin >> arr[i];

		check[arr[i] % 42] = true;
	}

	int ans = 0;

	for (int j = 0; j < 42; j++) {

		if (check[j] == true) {

			ans++;

		}

	}

	cout << ans << '\n';

	return 0;
}