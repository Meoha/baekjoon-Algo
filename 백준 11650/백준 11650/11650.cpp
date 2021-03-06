#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	
	cin >> N;

	for (int i = 0; i < N; i++) {

		int a, b;

		cin >> a >> b;

		v.push_back(make_pair(a, b));

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {

		cout << v[i].first << " " << v[i].second << '\n';

	}

	return 0;
}