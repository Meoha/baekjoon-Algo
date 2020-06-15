#include <iostream>

using namespace std;

int T;
int N;
int ans;

void sol(int result) {

	if (N == result) {

		ans++;

		return;

	}
	else if(N > result){

		for (int i = 1; i <= 3; i++) {

			sol(result + i);

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> N;

		ans = 0;

		sol(0);

		cout << ans << '\n';

	}

	return 0;
}