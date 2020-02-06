#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];

int main() {

	cin >> N;

	for (int n = 0; n < N; n++) {

		cin >> arr[n];

	}

	sort(arr, arr + N);

	int ans = 0;

	for (int n = 0; n < N; n++) {

		ans = ans + arr[n] * (N - n);

	}

	cout << ans << '\n';

	return 0;
}