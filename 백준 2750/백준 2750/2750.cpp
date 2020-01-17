#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; 

	cin >> N; 

	for (int n = 0; n < N; n++) {

		cin >> arr[n];

	}
	
	sort(arr, arr + N);

	for (int n = 0; n < N; n++) {

		cout << arr[n] << '\n';

	}
	return 0;
}