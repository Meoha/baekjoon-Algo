#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {

		int x, y;

		cin >> x >> y;

		v.push_back(make_pair(y, x));

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {

		cout << v[i].second << " " << v[i].first << '\n';
		
	}

	return 0;
}