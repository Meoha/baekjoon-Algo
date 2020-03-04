#include <string>
#include <vector>
#include <iostream>

using namespace std;

int razor_cnt = 0;

vector<string> decompose_string(string s) {

	vector<string> decompose;
	string temp = "";
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {

		temp = temp + s[i];

		if (s[i] == '(') {

			cnt++;

		}
		else {

			cnt--;

		}

		if (cnt == 0) {

			decompose.push_back(temp);
			temp = "";

		}

	}

	return decompose;
}

int cut_pipe(string t) {

	if (t == "()") {

		return 0;
	}

	vector<string> d = decompose_string(t);

	int razor_cnt = 0;

	if (d.size() != 0) {
		for (int j = 0; j < d.size(); j++) {

			string temp = d[j].substr(1, d[j].length() - 2);

			if (temp == "") {

				continue;
			}

			for (int r = 0; r < temp.length() - 1; r++) {

				if (temp[r] == '(' && temp[r + 1] == ')') {

					razor_cnt++;

				}

			}

			if (temp != "") {

				cout << razor_cnt + 1 << '\n';
				return ((razor_cnt + 1) + cut_pipe(temp));
			}

		}

	}

}

int solution(string arrangement) {
	int answer = 0;

	answer = cut_pipe(arrangement);

	return answer;
}

int main() {

	int a = solution("()(((()())(())()))(())");

	cout << a;

	return 0;
}