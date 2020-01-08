#include <iostream>
#include <algorithm>

using namespace std;

int N; //�������� ũ��
int board[21][21]; //������ ����
int part[21][21]; //���ű� ����
int people[6]; //�α� ����
int ans = 40000;

void init() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			part[i][j] = 0;

		}
	}

	for (int i = 1; i <= 5; i++) {

		people[i] = 0;

	}

	return;
}

//�ּڰ� ���
void calc_people() {

	//���ű� �α� ���
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (part[i][j] == 1) {

				people[1] = people[1] + board[i][j];

			}
			else if (part[i][j] == 2) {

				people[2] = people[2] + board[i][j];

			}
			else if (part[i][j] == 3) {

				people[3] = people[3] + board[i][j];

			}
			else if (part[i][j] == 4) {

				people[4] = people[4] + board[i][j];

			}
			else if (part[i][j] == 5 || part[i][j] == 0) {

				people[5] = people[5] + board[i][j];

			}

		}
	}

	sort(people + 1, people + 6);

	if (ans > people[5] - people[1]) {

		ans = people[5] - people[1];
	}

	return;
}

//���ű� ������
void divide(int x, int y, int d1, int d2) {

	//�� 1 ��輱
	for (int i = 0; i <= d1; i++) {

		part[x + i][y - i] = 5;

	}

	//�� 2 ��輱
	for (int i = 0; i <= d2; i++) {

		part[x + i][y + i] = 5;

	}

	//�� 3 ��輱
	for (int i = 0; i <= d2; i++) {

		part[x + d1 + i][y - d1 + i] = 5;

	}

	//�� 4 ��輱
	for (int i = 0; i <= d1; i++) {

		part[x + d2 + i][y + d2 - i] = 5;

	}

	//1�� ���ű�
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {


			if (part[i][j] == 0) {

				part[i][j] = 1;

			}
			else {

				break;

			}

		}
	}

	//2�� ���ű�
	for (int i = 1; i <= x + d2; i++) {
		for (int j = N; j >= y + 1; j--) {

			if (part[i][j] == 0) {

				part[i][j] = 2;

			}
			else {

				break;

			}

		}
	}

	//3�� ���ű�
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {

			if (part[i][j] == 0) {

				part[i][j] = 3;

			}
			else {
				
				break;

			}

		}
	}

	//4�� ���ű�
	for (int i = N; i >= x + d2 + 1; i--) {
		for (int j = N; j >= y - d1 + d2; j--) {

			if (part[i][j] == 0) {

				part[i][j] = 4;

			}
			else {

				break;

			}

		}
	}



}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			cin >> board[i][j];

		}
	}

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int d1 = 1; d1 <= j - 1; d1++) {
				for (int d2 = 1; d2 <= N - j; d2++) {

					if (i + d1 + d2 <= N) {

						init();
						divide(i, j, d1, d2);
						calc_people();

					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}