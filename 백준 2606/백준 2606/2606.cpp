#include <iostream>
#include <queue>

using namespace std;

int N; //컴퓨터의 수
int M; //네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수
int map[101][101];
int visited[101];
int ans;
queue<int> q;


void bfs() {

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (int n = 1; n <= N; n++) {
			if (!visited[n] && map[a][n] == 1 && map[n][a] == 1) {
				q.push(n);
				visited[n] = 1;
				ans++;
			}
		}
	}

}

int main() {

	cin >> N;

	cin >> M;

	for (int m = 0; m < M; m++) {

		int a, b;

		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	q.push(1);

	visited[1] = 1;

	bfs();

	cout << ans << endl;



	return 0;
}