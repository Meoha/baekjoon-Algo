#include <iostream>
#include <math.h>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; //테스트 케이스의 개수

	cin >> T;

	int x1, y1, r1, x2, y2, r2;

	for (int t = 0; t < T; t++) {

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2) {

			cout << -1 << '\n';

		}
		else if (pow(x2 - x1, 2) + pow(y2 - y1, 2) == pow(r1 + r2, 2) || pow(x2 - x1, 2) + pow(y2 - y1, 2) == pow(r1 - r2, 2)) {

			cout << 1 << '\n';
		}
		else if (pow(x2 - x1, 2) + pow(y2 - y1, 2) > pow(r1 + r2, 2) || pow(x2 - x1, 2) + pow(y2 - y1, 2) < pow(r1 - r2, 2)) {

			cout << 0 << '\n';
		}
		else if (pow(x2 - x1, 2) + pow(y2 - y1, 2) < pow(r1 + r2, 2) && pow(x2 - x1, 2) + pow(y2 - y1, 2) > pow(r1 - r2, 2)) {

			cout << 2 << '\n';
		}

	}

	return 0;
}