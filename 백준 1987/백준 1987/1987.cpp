#include <iostream>
#include <string>

using namespace std;

int R; //세로
int C; //가로
int board[20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;

void dfs(int a, int b, int result, bool *visited) {


	if (ans < result) {
		ans = result;
	}

	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];

		if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visited[board[nx][ny]]) {
			visited[board[nx][ny]] = true;
			dfs(nx, ny, result + 1, visited);
			visited[board[nx][ny]] = false;
		}
	}

	return;
}


int main() {

	cin >> R >> C;

	for (int r = 0; r < R; r++) {
		string temp;

		cin >> temp;

		for (int c = 0; c < C; c++) {
			board[c][r] = temp[c] - 'A';
		}
	}

	bool v[30] = { false };
	v[board[0][0]] = true;
	dfs(0, 0, 1, v);

	cout << ans << endl;

	return 0;
}
