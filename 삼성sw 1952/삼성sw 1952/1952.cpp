#include <iostream>

using namespace std;

int T; //테스트 케이스 개수
int ticket[4]; //이용권 가격 정보
int month[12]; //12개월 이용 계획 정보
int ans;

//초기화 함수
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

		//1일 이용권을 이용하는 경우
		sol(last + 1, result + ticket[0] * month[last]);

		//1달 이용권을 이용하는 경우
		sol(last + 1, result + ticket[1]);

		//3달 이용권을 이용하는 경우
		sol(last + 3, result + ticket[2]);

	}

	return;
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		//초기화
		init();

		//이용권 가격 정보 입력
		for (int i = 0; i < 4; i++) {

			cin >> ticket[i];

		}

		//12개월 이용 계획 정보 입력
		for (int m = 0; m < 12; m++) {

			cin >> month[m];

		}

		ans = ticket[3];

		//sol
		sol(0, 0);

		//출력
		cout << "#" << t << " " << ans << "\n";

	}

	return 0;
}