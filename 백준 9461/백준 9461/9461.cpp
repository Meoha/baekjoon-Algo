#include <iostream>

using namespace std;

int N;
long long arr[101];

void sol() {

	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;

	for (int i = 6; i <= N; i++) {

		arr[i] = arr[i - 5] + arr[i - 1];

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;
	
	for (int t = 0; t < T; t++) {

		cin >> N;

		sol();

		cout << arr[N] << '\n';

	}

	return 0;
}