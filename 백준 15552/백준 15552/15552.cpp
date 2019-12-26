#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		int A, B;

		cin >> A >> B;

		cout << A + B << '\n';

	}


	return 0;
}