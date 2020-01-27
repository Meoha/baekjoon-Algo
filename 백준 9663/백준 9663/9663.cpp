#include <iostream>
#include <vector>

using namespace std;

int N;
int ans;
vector<pair<int, int>> v;
int arr[15];

void sol(int last_y) {

	if (last_y > N) {
		
		ans++;

		return;
	}
	else {

		for (int j = 1; j <= N; j++) {
			bool flag = true;

			for (int a = 1; a < last_y; a++) {

				int x = arr[a];
				int y = a;

				if (x == j || x + y == last_y + j || y - x == last_y - j) {

					flag = false;

					break;
				}

			}

			if (flag) {

				arr[last_y] = j;

				sol(last_y + 1);

			}

		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	sol(1);

	cout << ans << '\n';

	return 0;
}