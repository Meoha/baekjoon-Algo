#include <iostream>

using namespace std;

int T; //�׽�Ʈ ���̽� ����
int ticket[4]; //�̿�� ���� ����
int month[12]; //12���� �̿� ��ȹ ����
int ans;

//�ʱ�ȭ �Լ�
void init() {

	for (int i = 0; i < 4; i++) {

		ticket[i] = 0;

	}

	for (int m = 0; m < 12; m++) {

		month[m] = 0;

	}

	return;
}

void sol(int last, int result) {

	if (last >= 12) {

		if (ans > result) {
			ans = result;
		}
	}
	else {

		//1�� �̿���� �̿��ϴ� ���
		sol(last + 1, result + ticket[0] * month[last]);

		//1�� �̿���� �̿��ϴ� ���
		sol(last + 1, result + ticket[1]);

		//3�� �̿���� �̿��ϴ� ���
		sol(last + 3, result + ticket[2]);

	}

	return;
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		//�ʱ�ȭ
		init();

		//�̿�� ���� ���� �Է�
		for (int i = 0; i < 4; i++) {

			cin >> ticket[i];

		}

		//12���� �̿� ��ȹ ���� �Է�
		for (int m = 0; m < 12; m++) {

			cin >> month[m];

		}

		ans = ticket[3];

		//sol
		sol(0, 0);

		//���
		cout << "#" << t << " " << ans << "\n";

	}

	return 0;
}