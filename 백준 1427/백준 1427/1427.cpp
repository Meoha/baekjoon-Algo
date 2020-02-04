#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[10];

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {

		arr[i] = s[i] - '0';

	}

	sort(arr, arr + s.length());

	for (int i = s.length() - 1; i >= 0; i--) {

		cout << arr[i];

	}

	cout << '\n';

	return 0;
}