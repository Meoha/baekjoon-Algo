#include <iostream>
#include <math.h>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long N;

	cin >> N;

	long long i = 0;
	long long sum = 1;

	if (N == 1) {

		cout << 1 << '\n';

	}
	else {

		while (sum < N) {

			sum = sum + (6 * i);

			i++;
		}

		cout << i << '\n';

	}

	return 0;
}