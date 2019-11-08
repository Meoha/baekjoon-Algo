#include <iostream>
#include <queue>

using namespace std;

int T; //�׽�Ʈ ���̽��� ����
int N; //�ͳ� ���� ũ��
int M; //�ͳ� ���� ũ��
int R; //��Ȧ �Ѳ� ���� ��ġ
int C; //��Ȧ �Ѳ� ���� ��ġ
int L; //Ż�� �� �ҿ�� �ð�
int tmap[50][50]; //�ͳ� ���� ����
bool visited[50][50];
queue<pair<pair<int, int>, int>> q;
int answer;

void init() {

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			tmap[n][m] = 0;
			visited[n][m] = false;
		}
	}

	answer = 0;

	while (!q.empty()) {
		q.pop();
	}

}

void sol(int a, int b) {

	q.push(make_pair(make_pair(a, b), 1));
	visited[b][a] = true;

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;

		q.pop();

		if (t > L) {
			return;
		}
		else {
			answer++;

			if (tmap[y][x] == 1) {

				//������ ���� ����
				if ((tmap[y - 1][x] == 1 || tmap[y - 1][x] == 2 || tmap[y - 1][x] == 5 || tmap[y - 1][x] == 6) && (y - 1 >= 0 && y - 1 < N && x >= 0 && x < M) && !visited[y - 1][x]) {
					visited[y - 1][x] = true;
					q.push(make_pair(make_pair(x, y - 1), t + 1));
				}

				//�Ϸ� ���� ����
				if ((tmap[y + 1][x] == 1 || tmap[y + 1][x] == 2 || tmap[y + 1][x] == 4 || tmap[y + 1][x] == 7) && (y + 1 >= 0 && y + 1 < N && x >= 0 && x < M) && !visited[y + 1][x]) {
					visited[y + 1][x] = true;
					q.push(make_pair(make_pair(x, y + 1), t + 1));
				}

				//�·� ���� ����
				if ((tmap[y][x - 1] == 1 || tmap[y][x - 1] == 3 || tmap[y][x - 1] == 4 || tmap[y][x - 1] == 5) && (y >= 0 && y < N && x - 1 >= 0 && x - 1 < M) && !visited[y][x - 1]) {
					visited[y][x - 1] = true;
					q.push(make_pair(make_pair(x - 1, y), t + 1));
				}

				//��� ���� ����
				if ((tmap[y][x + 1] == 1 || tmap[y][x + 1] == 3 || tmap[y][x + 1] == 6 || tmap[y][x + 1] == 7) && (y >= 0 && y < N && x + 1 >= 0 && x + 1 < M) && !visited[y][x + 1]) {
					visited[y][x + 1] = true;
					q.push(make_pair(make_pair(x + 1, y), t + 1));
				}
			}
			//������ 2�� ���
			else if (tmap[y][x] == 2) {

				//������ ���� ����
				if ((tmap[y - 1][x] == 1 || tmap[y - 1][x] == 2 || tmap[y - 1][x] == 5 || tmap[y - 1][x] == 6) && (y - 1 >= 0 && y - 1 < N && x >= 0 && x < M) && !visited[y - 1][x]) {
					visited[y - 1][x] = true;
					q.push(make_pair(make_pair(x, y - 1), t + 1));
				}

				//�Ϸ� ���� ����
				if ((tmap[y + 1][x] == 1 || tmap[y + 1][x] == 2 || tmap[y + 1][x] == 4 || tmap[y + 1][x] == 7) && (y + 1 >= 0 && y + 1 < N && x >= 0 && x < M) && !visited[y + 1][x]) {
					visited[y + 1][x] = true;
					q.push(make_pair(make_pair(x, y + 1), t + 1));
				}

			}
			//������ 3�� ���
			else if (tmap[y][x] == 3) {

				//�·� ���� ����
				if ((tmap[y][x - 1] == 1 || tmap[y][x - 1] == 3 || tmap[y][x - 1] == 4 || tmap[y][x - 1] == 5) && (y >= 0 && y < N && x - 1 >= 0 && x - 1 < M) && !visited[y][x - 1]) {
					visited[y][x - 1] = true;
					q.push(make_pair(make_pair(x - 1, y), t + 1));
				}

				//��� ���� ����
				if ((tmap[y][x + 1] == 1 || tmap[y][x + 1] == 3 || tmap[y][x + 1] == 6 || tmap[y][x + 1] == 7) && (y >= 0 && y < N && x + 1 >= 0 && x + 1 < M) && !visited[y][x + 1]) {
					visited[y][x + 1] = true;
					q.push(make_pair(make_pair(x + 1, y), t + 1));
				}
			}
			//������ 4�� ���
			else if (tmap[y][x] == 4) {

				//������ ���� ����
				if ((tmap[y - 1][x] == 1 || tmap[y - 1][x] == 2 || tmap[y - 1][x] == 5 || tmap[y - 1][x] == 6) && (y - 1 >= 0 && y - 1 < N && x >= 0 && x < M) && !visited[y - 1][x]) {
					visited[y - 1][x] = true;
					q.push(make_pair(make_pair(x, y - 1), t + 1));
				}

				//��� ���� ����
				if ((tmap[y][x + 1] == 1 || tmap[y][x + 1] == 3 || tmap[y][x + 1] == 6 || tmap[y][x + 1] == 7) && (y >= 0 && y < N && x + 1 >= 0 && x + 1 < M) && !visited[y][x + 1]) {
					visited[y][x + 1] = true;
					q.push(make_pair(make_pair(x + 1, y), t + 1));
				}
			}
			//������ 5�� ���
			else if (tmap[y][x] == 5) {

				//�Ϸ� ���� ����
				if ((tmap[y + 1][x] == 1 || tmap[y + 1][x] == 2 || tmap[y + 1][x] == 4 || tmap[y + 1][x] == 7) && (y + 1 >= 0 && y + 1 < N && x >= 0 && x < M) && !visited[y + 1][x]) {
					visited[y + 1][x] = true;
					q.push(make_pair(make_pair(x, y + 1), t + 1));
				}

				//��� ���� ����
				if ((tmap[y][x + 1] == 1 || tmap[y][x + 1] == 3 || tmap[y][x + 1] == 6 || tmap[y][x + 1] == 7) && (y >= 0 && y < N && x + 1 >= 0 && x + 1 < M) && !visited[y][x + 1]) {
					visited[y][x + 1] = true;
					q.push(make_pair(make_pair(x + 1, y), t + 1));
				}
			}
			//������ 6�� ���
			else if (tmap[y][x] == 6) {

				//�Ϸ� ���� ����
				if ((tmap[y + 1][x] == 1 || tmap[y + 1][x] == 2 || tmap[y + 1][x] == 4 || tmap[y + 1][x] == 7) && (y + 1 >= 0 && y + 1 < N && x >= 0 && x < M) && !visited[y + 1][x]) {
					visited[y + 1][x] = true;
					q.push(make_pair(make_pair(x, y + 1), t + 1));
				}

				//�·� ���� ����
				if ((tmap[y][x - 1] == 1 || tmap[y][x - 1] == 3 || tmap[y][x - 1] == 4 || tmap[y][x - 1] == 5) && (y >= 0 && y < N && x - 1 >= 0 && x - 1 < M) && !visited[y][x - 1]) {
					visited[y][x - 1] = true;
					q.push(make_pair(make_pair(x - 1, y), t + 1));
				}

			}
			//������ 7�� ���
			else if (tmap[y][x] == 7) {

				//������ ���� ����
				if ((tmap[y - 1][x] == 1 || tmap[y - 1][x] == 2 || tmap[y - 1][x] == 5 || tmap[y - 1][x] == 6) && (y - 1 >= 0 && y - 1 < N && x >= 0 && x < M) && !visited[y - 1][x]) {
					visited[y - 1][x] = true;
					q.push(make_pair(make_pair(x, y - 1), t + 1));
				}

				//�·� ���� ����
				if ((tmap[y][x - 1] == 1 || tmap[y][x - 1] == 3 || tmap[y][x - 1] == 4 || tmap[y][x - 1] == 5) && (y >= 0 && y < N && x - 1 >= 0 && x - 1 < M) && !visited[y][x - 1]) {
					visited[y][x - 1] = true;
					q.push(make_pair(make_pair(x - 1, y), t + 1));
				}
			}
		}
	}
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		//�׽�Ʈ ���̽��� ����
		init();

		cin >> N >> M >> R >> C >> L;

		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {

				cin >> tmap[n][m];

			}
		}

		if (L == 1) {
			answer = 1;
		}
		else if (L > 1) {
			sol(C, R);
		}

		cout << '#' << t << ' ' << answer << '\n';

	}

	return 0;
}