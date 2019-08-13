#include <iostream>

using namespace std;

int N, M;
int ans;
int map[1001][1001];
bool visited[1001];

void solution(int n) {

	if (!visited[n]) {
		visited[n] = true;
	}
	else {
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (map[n][i] == 1 && !visited[i]) {
			solution(i);
		}
	}
}

int main() {

	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int a, b;

		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			solution(i);
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}