#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; //��ٸ��� ��
int M; //���� ��
vector<pair<int, int>> mov; //��ٸ��� ���� ��ġ
queue<pair<int, int>> q; //���� ��ġ �� ����
bool visited[101];
int ans;

//��ٸ��� ���� ��ġ Ȯ��
int check_mov(int a) {

	for (int i = 0; i < mov.size(); i++) {

		if (mov[i].first == a) {

			return mov[i].second;

		}

	}

	return a;
}

void sol() {

	//1���� ����
	for (int i = 2; i <= 7; i++) {

		int m = check_mov(i);
		q.push({ m, 1 });
		visited[m] = true;

	}

	while (!q.empty()) {

		int x = q.front().first;
		int turn = q.front().second;

		q.pop();

		if (x >= 100) {

			ans = turn;

			return;
		}

		for (int i = 1; i <= 6; i++) {

			int nx = check_mov(x + i);

			if (!visited[nx]) {

				q.push({ nx, turn + 1 });
				visited[nx] = true;

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {

		int a, b = 0;

		cin >> a >> b;

		mov.push_back(make_pair(a, b));

	}

	//sol
	sol();

	cout << ans << '\n';

	return 0;
}