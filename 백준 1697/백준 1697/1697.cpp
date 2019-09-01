#include <iostream>
#include <queue>

using namespace std;

int N; //수빈이의 위치
int K; //동생의 위치
int visited[100001];
queue<int> q;

void bfs() {

	while (!q.empty()) {

		int x = q.front();

		q.pop();

		if (x == K) {

			cout << visited[x] - 1 << endl;

			return;
		}

		if ((x * 2) <= 100000 && (x * 2) >= 0 && !visited[x * 2]) {
			q.push(x * 2);
			visited[x * 2] = visited[x] + 1;
		}

		if ((x + 1) <= 100000 && (x + 1) >= 0 && !visited[x + 1]) {
			q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}

		if ((x - 1) <= 100000 && (x - 1) >= 0 && !visited[x - 1]) {
			q.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}

	}


}

int main() {

	cin >> N >> K;

	q.push(N);
	visited[N] = 1;
	bfs();

	return 0;
}