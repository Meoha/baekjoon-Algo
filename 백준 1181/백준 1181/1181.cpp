#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, string>> v;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {

		string s;
		
		cin >> s;

		v.push_back(make_pair(s.length(), s));

	}

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {

		cout << v[i].second << '\n';

	}

	return 0;
}