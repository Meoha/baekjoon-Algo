#include <iostream>
#include <cmath>

using namespace std;

int T; //테스트 케이스의 개수
int K; //자석을 회전시키는 횟수
int magnetic[8][4]; //자석의 자성정보
int turn[20][2]; //회전 정보
int isTurn[4]; //한턴당 회전정보
int ans;

//초기화 함수
void init() {

	ans = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {

			magnetic[j][i] = 0;

		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 2; j++) {

			turn[i][j] = 0;

		}
	}

	return;
}

//자석 회전 후 자성 정보
void afterTurn() {

	for (int i = 0; i < 4; i++) {

		//시계방향 회전
		if (isTurn[i] == 1) {

			int temp1 = magnetic[0][i];
			int temp2 = 0;
			int temp3 = magnetic[7][i];

			for (int j = 0; j < 7; j++) {

				temp2 = magnetic[j + 1][i];
				magnetic[j + 1][i] = temp1;
				temp1 = temp2;
			}

			magnetic[0][i] = temp3;


		}
		//반시계방향 회전
		else if(isTurn[i] == -1){

			int temp1 = magnetic[7][i];
			int temp2 = 0;
			int temp3 = magnetic[0][i];

			for (int j = 0; j < 7; j++) {

				temp2 = magnetic[7 - j - 1][i];
				magnetic[7 - j - 1][i] = temp1;
				temp1 = temp2;

			}

			magnetic[7][i] = temp3;

		}

	}

	return;
}

void sol() {

	for (int k = 0; k < K; k++) {

		for (int i = 0; i < 4; i++) {
			isTurn[i] = 0;
		}

		//회전할 때의 변화
		//1번 자석
		if (turn[k][0] == 1) {

			//시계방향
			if (turn[k][1] == 1) {

				isTurn[0] = 1;

				if (magnetic[2][0] != magnetic[6][1]) {

					isTurn[1] = -1;

					if (magnetic[2][1] != magnetic[6][2]) {
						isTurn[2] = 1;

						if (magnetic[2][2] != magnetic[6][3]) {
							isTurn[3] = -1;
						}
					}
				}
			}
			//반시계방향
			else if (turn[k][1] == -1) {

				isTurn[0] = -1;

				if (magnetic[2][0] != magnetic[6][1]) {

					isTurn[1] = 1;

					if (magnetic[2][1] != magnetic[6][2]) {
						isTurn[2] = -1;

						if (magnetic[2][2] != magnetic[6][3]) {
							isTurn[3] = 1;
						}
					}
				}
			}
		}
		//2번 자석
		else if (turn[k][0] == 2) {
			//시계방향
			if (turn[k][1] == 1) {

				isTurn[1] = 1;

				if (magnetic[2][0] != magnetic[6][1]) {

					isTurn[0] = -1;
				}

				if (magnetic[2][1] != magnetic[6][2]) {
					isTurn[2] = -1;

					if (magnetic[2][2] != magnetic[6][3]) {
						isTurn[3] = 1;
					}
				}

			}
			//반시계방향
			else if (turn[k][1] == -1) {

				isTurn[1] = -1;

				if (magnetic[2][0] != magnetic[6][1]) {

					isTurn[0] = 1;
				}

				if (magnetic[2][1] != magnetic[6][2]) {
					isTurn[2] = 1;

					if (magnetic[2][2] != magnetic[6][3]) {
						isTurn[3] = -1;
					}
				}
			}
		}
		//3번 자석
		else if (turn[k][0] == 3) {
			//시계방향
			if (turn[k][1] == 1) {

				isTurn[2] = 1;

				if (magnetic[2][1] != magnetic[6][2]) {

					isTurn[1] = -1;

					if (magnetic[2][0] != magnetic[6][1]) {
						isTurn[0] = 1;
					}
				}

				if (magnetic[2][2] != magnetic[6][3]) {
					isTurn[3] = -1;
				}

			}
			//반시계방향
			else if (turn[k][1] == -1) {

				isTurn[2] = -1;

				if (magnetic[2][1] != magnetic[6][2]) {

					isTurn[1] = 1;

					if (magnetic[2][0] != magnetic[6][1]) {
						isTurn[0] = -1;
					}
				}

				if (magnetic[2][2] != magnetic[6][3]) {
					isTurn[3] = 1;
				}
			}
		}
		//4번 자석
		else if (turn[k][0] == 4) {
			//시계방향
			if (turn[k][1] == 1) {

				isTurn[3] = 1;

				if (magnetic[2][2] != magnetic[6][3]) {

					isTurn[2] = -1;

					if (magnetic[2][1] != magnetic[6][2]) {
						
						isTurn[1] = 1;

						if (magnetic[2][0] != magnetic[6][1]) {

							isTurn[0] = -1;

						}

					}
				}

			}
			//반시계방향
			else if (turn[k][1] == -1) {

				isTurn[3] = -1;

				if (magnetic[2][2] != magnetic[6][3]) {

					isTurn[2] = 1;

					if (magnetic[2][1] != magnetic[6][2]) {

						isTurn[1] = -1;

						if (magnetic[2][0] != magnetic[6][1]) {

							isTurn[0] = 1;

						}

					}
				}

			}
		}

		//회전 후 변화
		afterTurn();
	}

	//계산
	for (int i = 0; i < 4; i++) {

		int a = 0;

		if (magnetic[0][i] != 0) {
			a = pow(2, i);
		}

		ans = ans + a;
	}

	return;
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> K;

		//초기화
		init();

		//자석의 자성에 대한 정보 입력
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {

				cin >> magnetic[j][i];

			}
		}

		//회전 정보 입력
		for (int k = 0; k < K; k++) {
			for (int l = 0; l < 2; l++) {

				cin >> turn[k][l];

			}
		}

		//sol
		sol();

		//출력
		cout << "#" << t << " " << ans << "\n";

	}

	return 0;
}