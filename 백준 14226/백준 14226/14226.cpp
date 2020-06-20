#include <iostream>
#include <queue>

using namespace std;

typedef struct {

	int emo; //ȭ�� �̸�Ƽ�� ����
	int clip; //Ŭ������ �̸�Ƽ�� ����
	int t; //�ɸ� �ð�

} emoticon;

int S; //������ �̸�Ƽ�� ����
queue<emoticon> q;
bool visited[2001][2001];
int ans;

void sol() {

	q.push({ 1, 0, 0 });
	visited[1][0] = true;

	while (!q.empty()) {

		int e = q.front().emo;
		int c = q.front().clip;
		int a = q.front().t;

		q.pop();

		if (e == S) {

			ans = a;

			return;
		}

		//ȭ�鿡 �ִ� �̸�Ƽ�� ��� ���� ��, Ŭ������ ����
		if (e >= 1 && e <= 2000 && !visited[e][e]) {

			q.push({ e, e, a + 1 });
			visited[e][e] = true;

		}

		//Ŭ�����忡 �ִ� ��� �̸�Ƽ�� �ٿ��ֱ�
		if (c >= 1 && e + c <= 2000 && !visited[e + c][c]) {

			q.push({ e + c, c, a + 1 });
			visited[e + c][c] = true;

		}

		//ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� ����
		if (e >= 1 && e <= 2000 && !visited[e - 1][c]) {

			q.push({ e - 1, c, a + 1 });
			visited[e - 1][c] = true;

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> S;

	//sol
	sol();

	cout << ans << '\n';

	return 0;
}