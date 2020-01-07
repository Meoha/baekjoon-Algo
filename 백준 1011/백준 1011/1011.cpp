#include <iostream>

using namespace std;

int main() {

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		long long x, y;

		cin >> x >> y;

		int ans = 0;
		long long MAX = 1;

		//증가하고 감소하는 구간을 사용하여 최고 속력 구하기
		while (MAX * MAX <= (y - x)) {

			MAX++;

		}

		MAX--;
		ans = 2 * MAX - 1;

		long long remain = (y - x) - (MAX * MAX);

		if (remain % MAX == 0) {
			
			ans = ans + remain / MAX;

		}
		else {

			ans = ans + remain / MAX + 1;

		}

		cout << ans << '\n';
	}

	return 0;
}