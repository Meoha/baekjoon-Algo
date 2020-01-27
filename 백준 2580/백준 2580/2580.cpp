#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int temp_board[9][9];
vector<pair<int, int>> v;

void sol(int n) {

	//종료 조건
	if (n == v.size()) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {

				temp_board[i][j] = board[i][j];

			}
		}

		return;
	}
	else {

		int x = v[n].first;
		int y = v[n].second;

		bool check[10] = { false };
	
		//가로 확인
		//세로 확인
		for (int i = 0; i < 9; i++) {

			check[board[y][i]] = true;
			check[board[i][x]] = true;

		}

		//사각형 확인
		int nx = (x / 3) * 3;
		int ny = (y / 3) * 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				check[board[ny + i][nx + j]] = true;

			}
		}

		for (int i = 1; i <= 9; i++) {

			if (!check[i]) {

				board[y][x] = i;
				sol(n + 1);
				board[y][x] = 0;

			}
		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			cin >> board[i][j];

			if (board[i][j] == 0) {

				v.push_back(make_pair(j, i));

			}

		}
	}

	//sol
	sol(0);

	//출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			cout << temp_board[i][j] << ' ';

		}

		cout << '\n';

	}

	return 0;
}