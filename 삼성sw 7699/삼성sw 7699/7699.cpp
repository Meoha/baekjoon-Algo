#include <iostream>
#include <string>

using namespace std;

int T; //테스트 케이스 개수
int R, C; //섬의 크기
char arr[20][20]; //섬의 명물 정보
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int ans;

//초기화 함수
void init() {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {

			arr[r][c] = NULL;

		}
	}

	ans = 0;

	return;
}

void sol(int x, int y, string s, bool visited[20][20]) {

	if (ans < s.length()) {

		ans = s.length();

	}

	for (int i = 0; i < 4; i++) {

		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visited[ny][nx]) {

			//알파벳 명물을 처음 볼 때
			if (s.find(arr[ny][nx]) == string::npos) {

				visited[ny][nx] = true;
				sol(nx, ny, s + arr[ny][nx], visited);
				visited[ny][nx] = false;

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; t++) {

		init();

		cin >> R >> C;

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {

				cin >> arr[r][c];

			}
		}

		bool visited[20][20] = { false }; //방문 배열

		visited[0][0] = true;
		string temp = "";
		
		//sol
		sol(0, 0, temp + arr[0][0], visited);

		cout << "#" << t << " " << ans << '\n';

	}

	return 0;
}