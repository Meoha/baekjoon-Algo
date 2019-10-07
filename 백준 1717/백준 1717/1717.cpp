#include <iostream>
#include <vector>

using namespace std;

int node[1000001];

int Find(int x) {

	if (x == node[x]) {
		return x;
	}
	else {
		return node[x] = Find(node[x]);
	}
}

void Union(int x, int y) {
	int a = Find(x);
	int b = Find(y);
	
	if (a != b) {
		node[b] = a;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		node[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int check, a, b;

		cin >> check >> a >> b;

		if (check == 0) {
			Union(a, b);
		}
		else if(check == 1){
			int x = Find(a);
			int y = Find(b);

			if (x == y) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	


	return 0;
}