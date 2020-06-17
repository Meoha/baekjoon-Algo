//두번째 풀었을 때
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;
int arr[20];
string MAX = "-987654321";
string MIN = "987654321";

void sol(int turn, int last, string s) {

	if (s.length() == K + 1) {

		if (MAX < s) {

			MAX = s;

		}

		if (MIN > s) {

			MIN = s;

		}

	}
	else {

		for (int i = 0; i <= 9; i++) {

			bool flag = true;

			for (int j = 0; j < s.length(); j++) {

				if (s[j] == i + '0') {

					flag = false;
					break;

				}

			}

			if (flag) {

				if (arr[turn] == 1) {

					if (last < i) {

						sol(turn + 1, i, s + to_string(i));

					}

				}
				else if (arr[turn] == 2) {

					if (last > i) {

						sol(turn + 1, i, s + to_string(i));

					}

				}

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> K;

	for (int k = 0; k < K; k++) {

		char c;

		cin >> c;

		if (c == '<') {

			arr[k] = 1;

		}
		else if (c == '>') {

			arr[k] = 2;

		}

	}

	//sol
	for (int a = 0; a <= 9; a++) {

		sol(0, a, to_string(a));

	}

	cout << MAX << '\n';
	cout << MIN << '\n';

	return 0;
}

/*
처음 풀었을 때

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;
int arr[20];
string MAX = "-987654321";
string MIN = "987654321";

void sol(int turn, int last, string s) {

	if (s.length() == K + 1) {

		if (MAX < s) {

			MAX = s;

		}

		if (MIN > s) {

			MIN = s;

		}

	}
	else {

		for (int i = 0; i <= 9; i++) {

			bool flag = true;

			for (int j = 0; j < s.length(); j++) {

				if (s[j] == i + '0') {

					flag = false;
					break;

				}

			}

			if (flag) {

				if (arr[turn] == 1) {

					if (last < i) {

						sol(turn + 1, i, s + to_string(i));
						
					}

				}
				else if (arr[turn] == 2) {

					if (last > i) {

						sol(turn + 1, i, s + to_string(i));

					}

				}

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> K;

	for (int k = 0; k < K; k++) {

		char c;

		cin >> c;

		if (c == '<') {

			arr[k] = 1;

		}
		else if (c == '>') {

			arr[k] = 2;

		}

	}

	//sol
	for (int a = 0; a <= 9; a++) {

		sol(0, a, to_string(a));

	}

	cout << MAX << '\n';
	cout << MIN << '\n';

	return 0;
}
*/