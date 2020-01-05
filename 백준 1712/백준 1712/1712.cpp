#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C;

	cin >> A >> B >> C;

	if (B >= C) {

		cout << -1 << '\n';

	}
	else {

		cout << A / (C - B) + 1 << '\n';

	}

	return 0;
}