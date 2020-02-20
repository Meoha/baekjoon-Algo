#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//���̷����� ���� �� �ִ� ��ġ
struct virus_loc {

	int x;
	int y;

};

struct virus {

	int vx; 
	int vy;
	int vt; //������ �ð�

};

int N; //�������� ũ��
int M; //���� �� �ִ� ���̷����� ����
int board[50][50]; //�������� ���� : 0�� �� ĭ, 1�� ��, 2�� ���̷����� ���� �� �ִ� ��ġ
bool visited[50][50];
virus_loc v[10];
int cnt_virus; //���̷����� ���� �� �ִ� ��ġ�� �� ����
int cnt_blank; //���̷����� �������ϴ� ��ġ�� �� ����
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<pair<pair<int, int>, int>> q;
int ans = 987654321;

void init() {

	while (!q.empty()) {
		
		q.pop();

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			visited[i][j] = false;

		}
	}

	return;
}

void bfs() {

	int cnt = 0;
	int result = 0;

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;

		q.pop();

		if (cnt == cnt_blank && board[y][x] != 2) {

			result = t;

		}

		for (int i = 0; i < 4; i++) {

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx] && board[ny][nx] != 1) {

				visited[ny][nx] = true;
				q.push({ { nx, ny }, t + 1 });
				
				if (board[ny][nx] == 0) {

					cnt++;

				}

			}

		}

	}


	if(cnt == cnt_blank){

		if (ans > result) {

			ans = result;

		}

	}

	return;
}

void combi(int last, vector<int> c) {

	if (c.size() == M) {

		init();

		for (int j = 0; j < c.size(); j++) {

			q.push({ {v[c[j]].x, v[c[j]].y}, 0 });
			visited[v[c[j]].y][v[c[j]].x] = true;
		
		}
		
		bfs();

		return;
	}
	else {

		for (int i = last; i < cnt_virus; i++) {

			c.push_back(i);
			combi(i + 1, c);
			c.pop_back();

		}
	}

}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> board[i][j];

			if (board[i][j] == 2) {

				v[cnt_virus].x = j;
				v[cnt_virus].y = i;
				cnt_virus++;

			}
			else if (board[i][j] == 0) {

				cnt_blank++;

			}

		}
	}

	//sol
	if (cnt_blank == 0) {

		cout << 0 << '\n';

		return 0;

	}

	vector<int> temp;

	combi(0, temp);

	if (ans == 987654321) {
		cout << -1 << '\n';

		return 0;
	}

	cout << ans << '\n';

	return 0;
}