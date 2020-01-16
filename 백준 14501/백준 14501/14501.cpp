#include <iostream>

using namespace std;

struct table {

	int T;
	int P;

};

int N; //퇴사 전 남은 N일
struct table t[16]; //상담 일정표
int ans; //최대 이익

void sol(int day, int profit) {

	if (day > N) {

		if (ans < profit) {
			
			ans = profit;

		}

		return;
	}
	else {

		//일을 선택할 경우
		if (day + t[day].T <= N + 1){

			sol(day + t[day].T, profit + t[day].P);

		}
		
		//일을 선택하지 않을 경우
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

	//출력
	cout << ans << '\n';

	return 0;
}