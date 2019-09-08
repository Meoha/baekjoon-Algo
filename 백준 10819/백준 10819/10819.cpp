#include <iostream>
#include <vector>

using namespace std;

int N; //주어지는 숫자의 개수
int map[8];
int ans;

int calc(vector<int> temp) {

	int result = 0;

	for (int i = 0; i < temp.size() - 1; i++) {

		int a, b = 0;

		a = temp[i];
		b = temp[i + 1];

		if ((a - b) < 0) {

			result = result - (a - b);

		}
		else {
			result = result + (a - b);
		}

	}

	return result;
}

void sol(vector<int> temp, bool *visited) {

	
	if (temp.size() == N) {

		int result = 0;

		result = calc(temp);

		if (ans < result) {
			ans = result;
		}

		return;
	}

	for (int i = 0; i < N; i++) {
		
		if (!visited[i]) {
			temp.push_back(map[i]);
			visited[i] = true;
			sol(temp, visited);
			temp.pop_back();
			visited[i] = false;
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> map[i];

	}

	//sol()
	vector<int> t;
	bool visited[8] = { false };

	sol(t, visited);

	cout << ans << endl;

	return 0;
}