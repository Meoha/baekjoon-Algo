#include <iostream>

using namespace std;

int main() {

	int N;

	cin >> N;

	int a = N / 5; //5kg ���� �ִ� ���
	int b = N / 3; //3kg ���� �ִ� ���
	
	for (int i = a; i >= 0; i--) {
		for (int j = 0; j <= b; j++) {

			if (i * 5 + j * 3 == N) {

				cout << i + j << '\n';

				return 0;
			}
			else if (i * 5 + j * 3 > N) {

				break;

			}

		}
	}

	cout << -1 << '\n';
	
	return 0;
}