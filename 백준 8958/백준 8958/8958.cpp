#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		int ans = 0;
		int cnt = 0;
		string s;

		cin >> s;

		for (int i = 0; i < s.length(); i++) {

			if (s[i] == 'O') {

				cnt = cnt + 1;
				ans = ans + cnt;

			}
			else {

				cnt = 0;

			}

		}

		cout << ans << '\n';

	}

	return 0;
}