#include <iostream>

using namespace std;

int T; //�׽�Ʈ ���̽��� ����
int N; //������ ����
int num[12]; //���� ����
int MIN, MAX; //�ּڰ�, �ִ�
int ans;

//�ʱ�ȭ �Լ�
void init() {

	ans = 0;
	MIN = 100000000;
	MAX = -100000000;

	for (int n = 0; n < N; n++) {

		num[n] = 0;

	}

	return;
}

void sol(int used, int result, int calc[4]) {

	if (used == N - 1) {

		if (MIN > result) {

			MIN = result;
		}

		if (MAX < result) {

			MAX = result;

		}

		return;
	}
	else {

		//������ ����ϴ� ���
		if (calc[0] > 0) {

			calc[0] = calc[0] - 1;

			sol(used + 1, result + num[used + 1], calc);

			calc[0] = calc[0] + 1;
		}

		//������ ����ϴ� ���
		if (calc[1] > 0) {

			calc[1] = calc[1] - 1;

			sol(used + 1, result - num[used + 1], calc);

			calc[1] = calc[1] + 1;
		}

		//������ ����ϴ� ���
		if (calc[2] > 0) {

			calc[2] = calc[2] - 1;

			sol(used + 1, result * num[used + 1], calc);

			calc[2] = calc[2] + 1;
		}

		//�������� ����ϴ� ���
		if (calc[3] > 0) {

			calc[3] = calc[3] - 1;

			sol(used + 1, result / num[used + 1], calc);

			calc[3] = calc[3] + 1;
		}

	}

	return;
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		init();

		cin >> N;

		int calc[4] = { 0, 0, 0, 0 };

		//��Ģ������ ���� ���� �Է�
		for (int i = 0; i < 4; i++) {

			cin >> calc[i];

		}

		//���� ���� �Է�
		for (int n = 0; n < N; n++) {

			cin >> num[n];

		}

		//sol
		sol(0, num[0], calc);

		ans = MAX - MIN;

		//���
		cout << "#" << t << " " << ans << "\n";

	}

	return 0;
}