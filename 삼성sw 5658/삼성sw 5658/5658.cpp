#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T; //테스트 케이스의 개수
int N; //주어지는 숫자 개수
int K; //K번째로 큰 수
int arr[28];
int m_arr[28];
int answer;

void move_num() {

	for (int i = 0; i < N - 1; i++) {
		m_arr[i + 1] = arr[i];
	}

	m_arr[0] = arr[N - 1];

	for (int i = 0; i < N; i++) {
		arr[i] = m_arr[i];
	}

	return;
}


void sol() {

	vector<int> ans;

	int length = N / 4;

	for (int l = 0; l < length; l++) {

		int num = 0;

		for (int i = N - 1; i >= 0; i--) {

			num = num + (arr[i] * (pow(16, (length - 1) - (i % length))));

			if (i % length == 0) {
				ans.push_back(num);
				num = 0;
			}

		}

		move_num();
	}

	sort(ans.begin(), ans.end(), greater<int>());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	answer = ans[K - 1];
	

	return;
}




int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> N >> K;

		string s;

		cin >> s;

		for (int n = 0; n < N; n++) {
			
			if (s[n] == '0') {
			arr[n] = 0;
			}
			else if (s[n] == '1') {
			arr[n] = 1;
			}
			else if (s[n] == '2') {
			arr[n] = 2;
			}
			else if (s[n] == '3') {
			arr[n] = 3;
			}
			else if (s[n] == '4') {
			arr[n] = 4;
			}
			else if (s[n] == '5') {
			arr[n] = 5;
			}
			else if (s[n] == '6') {
			arr[n] = 6;
			}
			else if (s[n] == '7') {
			arr[n] = 7;
			}
			else if (s[n] == '8') {
			arr[n] = 8;
			}
			else if (s[n] == '9') {
			arr[n] = 9;
			}
			else if (s[n] == 'A') {
				arr[n] = 10;
			}
			else if (s[n] == 'B') {
				arr[n] = 11;
			}
			else if (s[n] == 'C') {
				arr[n] = 12;
			}
			else if (s[n] == 'D') {
				arr[n] = 13;
			}
			else if (s[n] == 'E') {
				arr[n] = 14;
			}
			else if (s[n] == 'F') {
				arr[n] = 15;
			}

		}

		//sol
		sol();

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}