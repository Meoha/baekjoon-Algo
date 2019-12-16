#include <iostream>
#include <cmath>

using namespace std;

int T; //�׽�Ʈ ���̽��� ����
int K; //�ڼ��� ȸ����Ű�� Ƚ��
int magnetic[8][4]; //�ڼ��� �ڼ�����
int turn[20][2]; //ȸ�� ����
int isTurn[4]; //���ϴ� ȸ������
int ans;

//�ʱ�ȭ �Լ�
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

//�ڼ� ȸ�� �� �ڼ� ����
void afterTurn() {

	for (int i = 0; i < 4; i++) {

		//�ð���� ȸ��
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
		//�ݽð���� ȸ��
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

		//ȸ���� ���� ��ȭ
		//1�� �ڼ�
		if (turn[k][0] == 1) {

			//�ð����
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
			//�ݽð����
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
		//2�� �ڼ�
		else if (turn[k][0] == 2) {
			//�ð����
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
			//�ݽð����
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
		//3�� �ڼ�
		else if (turn[k][0] == 3) {
			//�ð����
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
			//�ݽð����
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
		//4�� �ڼ�
		else if (turn[k][0] == 4) {
			//�ð����
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
			//�ݽð����
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

		//ȸ�� �� ��ȭ
		afterTurn();
	}

	//���
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

		//�ʱ�ȭ
		init();

		//�ڼ��� �ڼ��� ���� ���� �Է�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {

				cin >> magnetic[j][i];

			}
		}

		//ȸ�� ���� �Է�
		for (int k = 0; k < K; k++) {
			for (int l = 0; l < 2; l++) {

				cin >> turn[k][l];

			}
		}

		//sol
		sol();

		//���
		cout << "#" << t << " " << ans << "\n";

	}

	return 0;
}