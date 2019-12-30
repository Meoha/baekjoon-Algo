#include <iostream>

using namespace std;

bool check[10000] = { false };

int selfnum(int a) {

	int result = a;


	while (1) {

		result = result + a % 10;
		a = a / 10;

		if (a == 0) {

			break;
		}
	
	}

	return result;
}

int main() {

	ios_base::sync_with_stdio(false);

	for (int i = 1; i < 10000; i++) {

		int temp = selfnum(i);

		if (temp < 10000) {
			check[temp] = true;
		}

	}

	for (int i = 1; i < 10000; i++) {

		if (!check[i]) {
			cout << i << '\n';
		}

	}

	return 0;
}