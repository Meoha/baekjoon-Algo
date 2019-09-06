#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L; //비밀번호 자릿수
int C; //주어지는 문자수
char s[15];
vector<string> ans;

void sol(int cnt, string pw) {

	if (pw.length() == L) {

		if (cnt >= 1 && L - cnt >= 2) {
			ans.push_back(pw);
		}

		return;
	}

	for (int i = 0; i < C; i++) {

		if (pw.length() == 0) {

			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				sol(cnt + 1, pw + s[i]);
			}
			else {
				sol(cnt, pw + s[i]);
			}
		}
		else {
			if (pw[pw.length() - 1] < s[i]) {
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
					sol(cnt + 1, pw + s[i]);
				}
				else {
					sol(cnt, pw + s[i]);
				}
			}
		}
	}

}


int main() {

	cin >> L >> C;

	for (int i = 0; i < C; i++) {

		cin >> s[i];

	}

	//sol

	sol(0, "");

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {

		cout << ans[i] << endl;
	}

	return 0;
}