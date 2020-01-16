#include <iostream>

using namespace std;

struct table {

	int T;
	int P;

};

int N; //��� �� ���� N��
struct table t[16]; //��� ����ǥ
int ans; //�ִ� ����

void sol(int day, int profit) {

	if (day > N) {

		if (ans < profit) {
			
			ans = profit;

		}

		return;
	}
	else {

		//���� ������ ���
		if (day + t[day].T <= N + 1){

			sol(day + t[day].T, profit + t[day].P);

		}
		
		//���� �������� ���� ���
		sol(day + 1, profit);
	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int n = 1; n <= N; n++) {

		cin >> t[n].T >> t[n].P;

	}

	//sol
	sol(1, 0);

	//���
	cout << ans << '\n';

	return 0;
}