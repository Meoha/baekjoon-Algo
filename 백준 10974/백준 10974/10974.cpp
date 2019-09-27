#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> list;

/*
void sol(bool *visited) {

	if (list.size() == N) {
		for (int i = 0; i < list.size(); i++) {

			cout << list[i] << ' ';
		}
		cout << '\n'; //cout << endl은 fflush()가 포함되어 있어 시간초과뜸

		return;
	}

	for (int i = 1; i <= N; i++) {

		if (!visited[i]) {
			visited[i] = true;
			list.push_back(i);

			sol(visited);

			visited[i] = false;
			list.pop_back();
		}
	}


}
*/

int main() {

	cin >> N;

	//bool visited[9] = { false };
	int list[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	//sol(visited);

	/*
	for (int i = 1; i <= N; i++) {
		list.push_back(i);
	}
	*/

	do {

		for (int i = 0; i < N; i++) {
			cout << list[i] << ' ';
		}
		
		cout << '\n';

	} while (next_permutation(list, list + N));
	

	return 0;
}