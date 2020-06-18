#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct mov {

	int X;
	int T;
	vector<int> v;

};

int N; //수빈이가 있는 위치
int K; //동생이 있는 위치
struct mov;
queue<mov> q;
bool visited[100001];
int ans;
vector<int> ans_v;

void sol() {

	q.push({ N, 0, {N} });
	visited[N] = true;

	while (!q.empty()) {

		int x = q.front().X;
		int t = q.front().T;
		vector<int> m = q.front().v;

		q.pop();

		if (x == K) {

			ans = t;
			ans_v = m;

			return;
		}
		else {

			if (x * 2 <= 100000 && x != 0) {
				if (!visited[x * 2]) {

					m.push_back(x * 2);
					q.push({ x * 2, t + 1, m });
					visited[x * 2] = true;
					m.pop_back();

				}
			}

			if (x + 1 <= 100000) {
				if (!visited[x + 1]) {

					m.push_back(x + 1);
					q.push({ x + 1, t + 1 , m });
					visited[x + 1] = true;
					m.pop_back();

				}
			}

			if (x - 1 >= 0 && x - 1 <= 100000) {
				if (!visited[x - 1]) {

					m.push_back(x - 1);
					q.push({ x - 1, t + 1 , m });
					visited[x - 1] = true;
					m.pop_back();

				}
			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	//sol
	if (K < N) {

		cout << N - K << '\n';

		for (int i = N; i >= K; i--) {

			cout << i << ' ';

		}

		cout << '\n';
	}
	else {

		sol();

		cout << ans << '\n';

		for (int i = 0; i < ans_v.size(); i++) {

			cout << ans_v[i] << ' ';

		}

		cout << '\n';

	}

	return 0;
}