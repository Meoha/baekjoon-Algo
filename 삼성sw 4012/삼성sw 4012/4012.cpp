#include <iostream>

using namespace std;

int T; //�׽�Ʈ ���̽��� ����
int N; //������� ��
int board[16][16]; //�ó��� ����
int ans;

//�ʱ�ȭ
void init() {

	ans = 987654321;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {

			board[m][n] = 0;

		}
	}

	return;
}


//������ ���� �ּҰ� �Ǵ� ��
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
				//����� i�� �����ϴ� ���
				selected[i] = true;

				sol(s + 1, selected, i + 1);

				//����� i�� �������� �ʴ� ���
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

		//����� �� �Է�
		cin >> N;

		//�ó��� ���� �Է�
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {

				cin >> board[m][n];

			}
		}

		bool selected[16] = { false };

		//sol
		sol(0, selected, 0);


		//���
		cout << "#" << t << " " << ans << "\n";


	}


	return 0;
}