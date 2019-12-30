#include <iostream>

using namespace std;

int main() {

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		int N;
		float score[1000] = { 0 };
		float sum = 0;

		cin >> N;

		for (int n = 0; n < N; n++) {

			cin >> score[n];

			sum = sum + score[n];
		}

		float avg = sum / N;
		float cnt = 0;

		for (int n = 0; n < N; n++) {

			if (avg < score[n]) {
				cnt++;
			}

		}

		float ans = cnt / N * 100;

		printf("%.3f%%\n", ans);

	}

	return 0;
}