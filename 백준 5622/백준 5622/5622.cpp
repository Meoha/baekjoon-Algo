#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;

	cin >> s;

	int ans = 0;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S') {
			ans = ans + 8;
		}
		else if (s[i] == 'T' || s[i] == 'U' || s[i] == 'V') {
			ans = ans + 9;
		}
		else if (s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z') {
			ans = ans + 10;
		}
		else {
			ans = ans + ((s[i] - 56) / 3);
		}

	}

	cout << ans << '\n';

	return 0;
}