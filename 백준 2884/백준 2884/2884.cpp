#include <iostream>

using namespace std;

int main() {

	int H, M;

	cin >> H >> M;

	if (M - 45 >= 0) {
		H = H;
		M = M - 45;
	}
	else if (M - 45 < 0) {
		H = H - 1;
		M = 60 + (M - 45);

		if (H < 0) {
			H = 24 + H;
		}
	}

	cout << H << ' ' << M << '\n';

	return 0;
}