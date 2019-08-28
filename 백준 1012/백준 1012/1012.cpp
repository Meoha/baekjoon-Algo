#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T; //�׽�Ʈ ���̽��� ����
int M; //���߹��� ���α���
int N; //���߹��� ���α���
int K; //���߰� �ɾ��� �ִ� ��ġ�� ����
int map[51][51]; //���߹�
bool visited[51][51];
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans;
vector<int> result; //������������ ���� ��

void sol() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

	ans++;
}

int main() {

	cin >> T;

	for(int t = 1; t <= T; t++){
	
		cin >> M >> N >> K;

		for (int k = 0; k < K; k++) {

			int a, b;

			cin >> a >> b;

			map[a][b] = 1;

		}

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {

				if (map[m][n] == 1 && !visited[m][n]) {

					q.push(make_pair(m, n));
					visited[m][n] = true;

					sol();
				}

			}
		}

		result.push_back(ans);

		ans = 0;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {

				map[m][n] = 0;
				visited[m][n] = false;
			}
		}

	}

	for (int v = 0; v < result.size(); v++) {
		
		cout << result[v] << endl;
	}

	return 0;
}