#include <iostream>
#include <queue>

using namespace std;

int T; //테스트 케이스의 개수
int N; //체스판의 한 변의 길이
int map[301][301];
int visited[301][301];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
queue<pair<int, int>> q;

void bfs() {

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[x][y] + 1;
				
				if (map[nx][ny] == 2) {
					cout << visited[nx][ny] - 1 << endl;

					return;
				}
			}

		}


	}


}

int main() {

	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> N;

		//시작 위치
		int x1, y1 = 0;

		cin >> x1 >> y1;

		map[x1][y1] = 1;

		int x2, y2 = 0;
		
		cin >> x2 >> y2;

		map[x2][y2] = 2;

		if (x1 == x2 && y1 == y2) {
			cout << 0 << endl;
		}
		else {
			q.push(make_pair(x1, y1));
			visited[x1][y1] = 1;

			bfs();

			while (!q.empty()) {
				q.pop();
			}

			for (int n = 0; n < 300; n++) {
				for (int m = 0; m < 300; m++) {
					visited[m][n] = 0;
				}
			}
		}

		map[x1][y1] = 0;
		map[x2][y2] = 0;
	}



	return 0;
}