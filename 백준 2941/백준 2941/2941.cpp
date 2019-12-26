#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;
	int ans = 0;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == 'c' && s[i + 1] == '=') {
			ans = ans + 1;
			i = i + 1;
		}
		else if (s[i] == 'c' && s[i + 1] == '-') {
			ans = ans + 1;
			i = i + 1;
		}
		else if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
			ans = ans + 1;
			i = i + 2;
		}
		else if (s[i] == 'd' && s[i + 1] == '-') {
			ans = ans + 1;
			i = i + 1;
		}
		else if (s[i] == 'l' && s[i + 1] == 'j') {
			ans = ans + 1;
			i = i + 1;
		}
		else if (s[i] == 'n' && s[i + 1] == 'j') {
			ans = ans + 1;
			i = i + 1;
		}
		else if (s[i] == 's' && s[i + 1] == '=') {
			ans = ans + 1;
			i = i + 1;
		}
		else if (s[i] == 'z' && s[i + 1] == '=') {
			ans = ans + 1;
			i = i + 1;
		}
		else {
			ans = ans + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}