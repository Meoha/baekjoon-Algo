#include <iostream>

using namespace std;

int N; //카드의 개수
int M; //카드의 합이 M 이하
int card[100]; //카드 리스트
int ans;

void sol(int num, int sum, int index) {

	if (num == 3) {

		if (ans < sum && sum <= M) {

			ans = sum;

		}

		return;
	}

	
	if (index < N) {
		
		//카드를 선택할 때
		sol(num + 1, sum + card[index], index + 1);

		//카드를 선택하지 않을 때
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