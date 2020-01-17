#include <iostream>

using namespace std;

struct people {

	int x;
	int y;
	int r = 1;

};

struct people p[50];

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> p[i].x >> p[i].y;

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (i != j) {

				if (p[i].x > p[j].x && p[i].y > p[j].y) {

					p[j].r++;

				}

			}

		}
	}

	for (int i = 0; i < N; i++) {

		cout << p[i].r << ' ';

	}

	cout << '\n';

	return 0;
}