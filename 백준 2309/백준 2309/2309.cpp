#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> height; //æ∆»© ≥≠¿Ô¿Ã

void sol() {

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			
			int sum = 0;
			
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) {
					continue;
				}
				else {
					sum = sum + height[k];
				}
			}

			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {
						continue;
					}
					else {
						cout << height[k] << endl;
					}
				}

				return;
			}
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++) {

		int temp = 0;

		cin >> temp;

		height.push_back(temp);

	}

	sort(height.begin(), height.end());

	sol();

	return 0;
}