#include <iostream>

using namespace std;

int sol(int n) {
	
	if (n == 1 || n == 0) {

		return 1;
	}
	else {

		return n * sol(n - 1);

	}
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;

	cout << sol(N) << '\n';

	return 0;
}