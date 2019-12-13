#include <iostream>

using namespace std;

int T; //테스트 케이스의 개수
int N; //식재료의 수
int board[16][16]; //시너지 정보
int ans;

//초기화
void init() {

	ans = 987654321;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {

			board[m][n] = 0;

		}
	}

	return;
}


//음식의 맛이 최소가 되는 값
void sol(int s, bool *selected, int last) {

	if (s == N / 2) {

		int food_A = 0;
		int food_B = 0;
		int result = 0;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {

				if (n != m && selected[m] && selected[n]) {
					food_A = food_A + board[m][n];
				}

				if (n != m && !selected[m] && !selected[n]) {
					food_B = food_B + board[m][n];
				}

			}
		}

		result = food_A - food_B;

		if (result < 0) {
			result = -result;
		}

		if (result < ans) {
			ans = result;
		}

		return;
	}
	else {

		for (int i = last; i < N; i++) {

			if ((N / 2 - last + s) >= 0) {
				//식재료 i를 선택하는 경우
				selected[i] = true;

				sol(s + 1, selected, i + 1);

				//식재료 i를 선택하지 않는 경우
				selected[i] = false;
			}
			else {
				break;
			}

		}
	}

	return;
}



int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		init();

		//식재료 수 입력
		cin >> N;

		//시너지 정보 입력
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {

				cin >> board[m][n];

			}
		}

		bool selected[16] = { false };

		//sol
		sol(0, selected, 0);


		//출력
		cout << "#" << t << " " << ans << "\n";


	}


	return 0;
}