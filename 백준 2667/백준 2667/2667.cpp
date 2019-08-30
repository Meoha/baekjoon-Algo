#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N; //정사각형의 가로, 세로 길이
int map[25][25];
bool visited[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
vector<int> ans;

void bfs() {

	int result = 1;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				result++;
			}
		}
	}

	ans.push_back(result);
}

int main() {

	cin >> N;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			
			int temp = 0;

			scanf("%1d", &temp);

			map[i][j] = temp;

		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {

			if (!visited[i][j] && map[i][j] == 1) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
				bfs();
			}
		}
	}

	cout << ans.size() << endl;

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {

		cout << ans[i] << endl;

	}

	return 0;
}