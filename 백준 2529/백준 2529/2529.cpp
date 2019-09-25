#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k; //�ε�ȣ ���� ����
int box[9]; //'>'�� ��� 1, '<'�� ��� -1
vector<string> ans;

void sol(string result, int idx, int last, bool *visited) {

	if (result.length() == (k + 1)) {

		ans.push_back(result);

		return;
	}
	else {

		for (int i = 0; i < 10; i++) {

			string temp;

			if (result.length() == 0) {
				temp = to_string(i);
				visited[i] = true;
				sol(temp, 0, i, visited);
				visited[i] = false;
			}
			else {
				if (!visited[i]) {
					if (box[idx] == -1) {
						if (last < i) {
							temp = result + to_string(i);
							visited[i] = true;
							sol(temp, idx + 1, i, visited);
							visited[i] = false;
						}
					}
					else if (box[idx] == 1) {
						if (last > i) {
							temp = result + to_string(i);
							visited[i] = true;
							sol(temp, idx + 1, i, visited);
							visited[i] = false;
						}
					}
				}
			}

		}

	}


}

int main() {

	cin >> k;

	for (int i = 0; i < k; i++) {
		char temp;

		cin >> temp;

		if (temp == '<') {
			box[i] = -1;
		}
		else if (temp == '>') {
			box[i] = 1;
		}
	}

	bool visited[10] = { false };


	sol("", 0, 0, visited);

	sort(ans.begin(), ans.end());

	cout << ans[ans.size() - 1] << endl << ans[0] << endl;

	return 0;
}