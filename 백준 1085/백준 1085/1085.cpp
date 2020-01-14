#include <iostream>

using namespace std;

int main() {

	int x, y; //한수의 위치
	int w, h; //직사각형 오른쪽 위 꼭짓점

	cin >> x >> y >> w >> h;

	int ans = w - x;

	if (ans > x) {

		ans = x;

	}

	if (ans > h - y) {

		ans = h - y;

	}

	if (ans > y) {

		ans = y;

	}

	cout << ans << '\n';

	return 0;
}