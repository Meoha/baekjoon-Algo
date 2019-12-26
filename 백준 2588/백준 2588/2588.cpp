#include <iostream>

using namespace std;

int main() {

	int A, B;

	cin >> A >> B;

	int ans[4] = { 0 };

	ans[0] = A * (B % 10);
	ans[1] = A * ((B / 10) % 10);
	ans[2] = A * ((B / 10) / 10);
	ans[3] = ans[0] + ans[1] * 10 + ans[2] * 100;

	for (int i = 0; i < 4; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}