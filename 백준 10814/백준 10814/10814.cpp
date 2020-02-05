#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<pair<int, int>, string>> v;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {

		int a;
		string s;

		cin >> a >> s;

		v.push_back({ { a, i}, s });

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {

		cout << v[i].first.first << " " << v[i].second << '\n';
		
	}

	return 0;
}