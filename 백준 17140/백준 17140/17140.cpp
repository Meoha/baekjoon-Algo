#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int r, c, k;
int r_num = 3; //행의 개수
int c_num = 3; //열의 개수
int arr[105][105];

int sol(int ans) {

	if (ans > 100) {

		return -1;
	}

	if (arr[r][c] == k) {

		return ans;
	}

	//R 연산
	if (r_num >= c_num) {

		int temp_arr[105][105] = {};
		int c_cnt = 0;

		for (int i = 1; i <= r_num; i++) {

			map<int, int> m;
			map<int, int>::iterator iter;
			vector<pair<int, int>> v;

			for (int j = 1; j <= c_num; j++) {

				m[arr[i][j]]++;

			}

			for (iter = m.begin(); iter != m.end(); iter++) {

				v.push_back(make_pair(iter->second, iter->first));


			}

			sort(v.begin(), v.end());

			if (v.size() * 2 > c_cnt) {

				c_cnt = v.size() * 2;
			}

			if (c_cnt > 100) {
				
				c_cnt = 100;

			}

			for (int k = 0; k < v.size(); k++) {

				if (k >= 50) {

					break;
				}

				temp_arr[i][k * 2 + 1] = v[k].second;
				temp_arr[i][k * 2 + 2] = v[k].first;
				//cout << v[k].first << ' ' << v[k].second << '\n';

			}

		}

		c_num = c_cnt;

		//cout << "rrrrrrrrr" << '\n';

		for (int i = 1; i <= r_num; i++) {
			for (int j = 1; j <= c_num; j++) {

				arr[i][j] = temp_arr[i][j];
				//cout << temp_arr[i][j] << ' ';
			}
			//cout << '\n';
		}

		sol(ans + 1);

	}
	//C 연산
	else {

		int temp_arr[105][105] = {};
		int r_cnt = 0;

		for (int j = 1; j <= c_num; j++) {

			map<int, int> m;
			map<int, int>::iterator iter;
			vector<pair<int, int>> v;

			for (int i = 1; i <= r_num; i++) {

				m[arr[i][j]]++;

			}

			for (iter = m.begin(); iter != m.end(); iter++) {

				v.push_back(make_pair(iter->second, iter->first));

			}

			sort(v.begin(), v.end());

			if (v.size() * 2 > r_cnt) {

				r_cnt = v.size() * 2;
			}

			if (r_cnt > 100) {

				r_cnt = 100;

			}

			for (int k = 0; k < v.size(); k++) {

				if (k >= 50) {

					break;
				}

				temp_arr[k * 2 + 1][j] = v[k].second;
				temp_arr[k * 2 + 2][j] = v[k].first;

				//cout << v[k].first << ' ' << v[k].second << '\n';
			}

		}

		r_num = r_cnt;

		//cout << "ccccccccccc" << '\n';

		for (int i = 1; i <= r_num; i++) {
			for (int j = 1; j <= c_num; j++) {

				arr[i][j] = temp_arr[i][j];
				//cout << temp_arr[i][j] << ' ';
			}
			//cout << '\n';
		}


		sol(ans + 1);


	}


}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {

			cin >> arr[i][j];

		}
	}

	//sol
	int answer = sol(0);

	cout << answer << '\n';

	return 0;
}