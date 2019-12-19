#include <iostream>
#include <string>

using namespace std;

int arr[26];

int main() {

	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {

		int a = s[i];

		if (a >= 65 && a <= 90) {
			arr[a - 65]++;
		}
		else if(a >= 97 && a <= 122) {
			arr[a - 97]++;
		}
	}

	int cnt = 0;
	int MAX = 0;
	char ans = ' ';

	for (int i = 0; i < 26; i++) {

		if (arr[i] > MAX) {
			MAX = arr[i];
			ans = i + 65;
			cnt = 1;
		}
		else if (arr[i] == MAX) {
			cnt++;
		}
	}

	if (cnt > 1) {

		cout << '?' << '\n';

	}
	else {

		cout << ans << '\n';

	}

	return 0;
}