#include <iostream>

using namespace std;

int main() {

	int x, y; //�Ѽ��� ��ġ
	int w, h; //���簢�� ������ �� ������

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