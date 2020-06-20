#include <iostream>
#include <queue>

using namespace std;

typedef struct {

	int emo; //화면 이모티콘 개수
	int clip; //클립보드 이모티콘 개수
	int t; //걸린 시간

} emoticon;

int S; //스마일 이모티콘 개수
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

		//화면에 있는 이모티콘 모두 복사 후, 클립보드 저장
		if (e >= 1 && e <= 2000 && !visited[e][e]) {

			q.push({ e, e, a + 1 });
			visited[e][e] = true;

		}

		//클립보드에 있는 모든 이모티콘 붙여넣기
		if (c >= 1 && e + c <= 2000 && !visited[e + c][c]) {

			q.push({ e + c, c, a + 1 });
			visited[e + c][c] = true;

		}

		//화면에 있는 이모티콘 중 하나를 삭제
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