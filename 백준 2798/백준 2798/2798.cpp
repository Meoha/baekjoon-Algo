#include <iostream>

using namespace std;

int N; //ī���� ����
int M; //ī���� ���� M ����
int card[100]; //ī�� ����Ʈ
int ans;

void sol(int num, int sum, int index) {

	if (num == 3) {

		if (ans < sum && sum <= M) {

			ans = sum;

		}

		return;
	}

	
	if (index < N) {
		
		//ī�带 ������ ��
		sol(num + 1, sum + card[index], index + 1);

		//ī�带 �������� ���� ��
		sol(num, sum, index + 1);

	}

	return;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> card[i];

	}

	sol(0, 0, 0);

	cout << ans << '\n';

	return 0;
}