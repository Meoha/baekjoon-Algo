#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int ans = -1000;

void sol() {
	
	int sum = 0;

	for (int i = 0; i < N; i++) {

		sum += arr[i];

		if (ans < sum) {

			ans = sum;

		}

		if (sum < 0) {

			sum = 0;

		}

	}
	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];

	}

	//sol
	sol();

	cout << ans << '\n';

	return 0;
}