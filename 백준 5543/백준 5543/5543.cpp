#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int ham[3];
	int bev[2];
	
	for (int i = 0; i < 3; i++) {

		cin >> ham[i];

	}

	for (int i = 0; i < 2; i++) {

		cin >> bev[i];

	}

	sort(ham, ham + 3);
	sort(bev, bev + 2);

	cout << ham[0] + bev[0] - 50 << '\n';

	return 0;
}