#include <iostream>
#include <string>

using namespace std;


int main() {

	string s;

	cin >> s;

	int arr[26] = {};

	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}

	for (int i = 0; i < s.length(); i++) {

		int a = 0;

		a = s[i] - 97;

		if (arr[a] == -1) {
			arr[a] = i;
		}

	}

	for (int i = 0; i < 26; i++) {

		cout << arr[i] << ' ';

	}

	cout << '\n';

	return 0;
}