#include <iostream>
#include <string>

using namespace std;

int T; //�׽�Ʈ ���̽��� ����

int main() {

	cin >> T;

	for (int t = 0; t < T; t++) {

		int N;
		string s;
		
		cin >> N >> s;

		string ans;
		
		for (int i = 0; i < s.length(); i++) {
			for (int n = 0; n < N; n++) {

				ans = ans + s[i];

			}
		}
		
		cout << ans << '\n';
	}


	return 0;
}