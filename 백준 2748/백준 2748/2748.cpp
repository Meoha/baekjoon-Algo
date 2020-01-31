#include <iostream>

using namespace std;

long long f[91];
int N;

long long fibo(int n) {

	f[1] = 1;
	f[2] = 1;

	for (int i = 3; i <= n; i++) {

		f[i] = f[i - 1] + f[i - 2];

	}

	return f[n];
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	long long ans = fibo(N);

	cout << ans << '\n';

	return 0;
}