#include <iostream>
#include <queue>

using namespace std;

int N; //정점의 개수
int M; //간선의 개수
int V; //탐색을 시작할 정점의 번호
int map[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int n) {

	if (!visited[n]) {
		visited[n] = true;

		cout << n << ' ';
	}
	else {
		return;
	}

	for (int i = 1; i <= N; i++) {

		if (map[n][i] == 1 && !visited[i]) {
			dfs(i);
		}

	}


}

void bfs() {

	while (!q.empty()) {

		int x = q.front();

		cout << x << ' ';

		q.pop();

		for (int i = 1; i <= N; i++) {

			if (map[x][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}

		}
	}
}


int main() {

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {

		int a, b = 0;

		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(V);

	cout << endl;

	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}

	q.push(V);
	visited[V] = true;

	bfs();

	cout << endl;

	return 0;
}