#include <iostream>
#include <string>
using namespace std;

int N;
int map[101][101];

//가로로 누울 수 있는 경우의 수
int horizontal() {

	int hori = 0;

	for (int i = 0; i < N; i++) {

		int rest = 0;

		for(int j = 0; j < N; j++){
			if (map[j][i] == 0) {
				rest++;
			}

			if (j == N - 1 || map[j][i] == 1) {
				if (rest >= 2) {
					hori++;
				}

				rest = 0;
			}
		}
	}

	return hori;
}

//세로로 누울 수 있는 경우의 수
int vertical() {
	int vert = 0;

	for (int j = 0; j < N; j++) {

		int rest = 0;

		for (int i = 0; i < N; i++) {
			if (map[j][i] == 0) {
				rest++;
			}

			if (i == N - 1 || map[j][i] == 1) {
				if (rest >= 2) {
					vert++;
				}

				rest = 0;
			}
		}
	}
	
	return vert;
}


int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;

		cin >> s;

		for (int j = 0; j < N; j++) {
			if (s[j] == '.') {
				map[j][i] = 0;
			}
			else if (s[j] == 'X') {
				map[j][i] = 1;
			}
		}
	}

	int a, b = 0;
	
	a = horizontal();
	b = vertical();

	cout << a << ' ' << b;

	return 0;
}