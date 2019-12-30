#include <iostream>

using namespace std;

int main() {

	int N;

	cin >> N;

	float arr[1000] = { 0 };
	float MAX = 0;

	for (int n = 0; n < N; n++) {

		cin >> arr[n];

		if (MAX < arr[n]) {

			MAX = arr[n];
		
		}

	}

	float avg = 0;

	for (int i = 0; i < N; i++) {

		avg = avg + (arr[i] / MAX * 100);

	}

	cout << avg / N << '\n';

	return 0;
}