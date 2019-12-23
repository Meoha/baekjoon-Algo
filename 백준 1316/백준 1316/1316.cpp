#include <iostream>
#include <string>

using namespace std;

int ans;


int main() {

	int N;

	cin >> N;

	for (int n = 0; n < N; n++) {

		string s;

		cin >> s;

		bool arr[26] = {false};

		int a = -1;
		int last = -1;
		bool flag = true;

		for (int i = 0; i < s.length(); i++) {

			a = s[i] - 97;

			if (arr[a] && last != a) {
				flag = false;

				break;
			}

			arr[a] = true;
			last = a;	

		}

		if (flag) {
			ans++;
		}

	}

	cout << ans << '\n';

	return 0;
}