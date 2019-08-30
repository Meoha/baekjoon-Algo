#include <iostream>
#include <queue>

using namespace std;

int N; //정점의 개수
int map[101][101];

void sol() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++)
			if (map[j][i] == 1 && map[i][k] == 1) {
				map[j][k] = 1;
			}
		}
	}

}

int main() {

	cin >> N;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {

			int temp = 0;

			cin >> temp;

			map[i][j] = temp;
		}
	}

	//solution
	sol();

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {

			cout << map[i][j] << ' ';

		}

		cout << endl;

	}


	return 0;
}