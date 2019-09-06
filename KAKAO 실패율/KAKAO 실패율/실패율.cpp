#include <string>
#include <vector>
#include <map>

using namespace std;

bool visited[500];

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	map<int, float> m;
	float num_user = stages.size();

	for (int i = 1; i <= N; i++) {
		float cnt = 0;

		for (int j = 0; j < stages.size(); j++) {
			if (stages[j] == i) {
				cnt++;
			}
		}

		if (num_user != 0) {
			m[i] = cnt / num_user;
			num_user = num_user - cnt;
		}
		else {
			m[i] = 0;
		}

	}

	int iter = 0;


	while (iter != N) {
		float MAX = -1;
		int check = 0;

		for (int i = 1; i <= N; i++) {
			if (MAX < m[i] && !visited[i]) {
				MAX = m[i];
				check = i;
			}
		}


		answer.push_back(check);
		visited[check] = true;
		iter++;
	}


	return answer;
}