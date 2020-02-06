#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long, long long>> v;
int ans;

void sol() {

	long long end = 0;

	for (int i = 0; i < N; i++) {

		if (end <= v[i].second) {

			end = v[i].first;
			ans++;
		}

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int n = 0; n < N; n++) {
		
		long long s, e;

		cin >> s >> e;

		v.push_back({ e, s });

	}

	sort(v.begin(), v.end());

	sol();
	
	cout << ans << '\n';

	return 0;
}