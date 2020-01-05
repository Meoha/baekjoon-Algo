#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, V;

	cin >> A >> B >> V;

	if (A == V) {

		cout << 1 << '\n';

	}
	else {

		if ((V - B) % (A - B) == 0) {

			cout << (V - B) / (A - B) << '\n';

		}
		else {

			cout << (V - B) / (A - B) + 1 << '\n';

		}

	}

	return 0;
}