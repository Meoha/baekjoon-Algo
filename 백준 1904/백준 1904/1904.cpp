#include <iostream>

using namespace std;

int N;
int arr[1000001];

void sol() {

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= N; i++) {

		arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;
 
	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	sol();

	cout << arr[N] << '\n';

	return 0;
}
