#include <iostream>
#include <vector>

using namespace std;

int N, M;

void sol(vector<int> v, int last) {

	if (v.size() == M) {

		for (int i = 0; i < M; i++) {

			cout << v[i] << ' ';

		}

		cout << '\n';

		return;
	}
	else {

		for (int i = last; i <= N; i++) {

			bool flag = true;

			for (int j = 0; j < v.size(); j++) {

				if (i == v[j]) {

					flag = false;

					break;

				}

			}

			if (flag) {

				v.push_back(i);

				sol(v, i + 1);

				v.pop_back();

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	vector<int> v;

	sol(v, 1);

	return 0;
}