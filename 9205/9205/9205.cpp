#include <iostream>

using namespace std;

int t; //테스트 케이스 개수
int n; //맥주를 파는 편의점의 개수
int beer_dist = 1000;
int map[102][2];
bool visited[102];

void dfs(int a) {
	visited[a] = true;

	int dist;


	for (int start = 1; start < n + 2; start++) {
			
		dist = abs(map[a][0] - map[start][0]) + abs(map[a][1] - map[start][1]);

		if (visited[start] == false && dist <= beer_dist) {			
			dfs(start);
		}
	}
}


int main(void) {

	cin >> t;

	for(int i = 0; i < t; i++){
	
		cin >> n;

		for (int j = 0; j < n + 2; j++) {

			int x, y;

			cin >> x >> y;

			map[j][0] = x;
			map[j][1] = y;
		}

		dfs(0);

		if (visited[n + 1] == false) {
			cout << "sad" << endl;
		}
		else {
			cout << "happy" << endl;
		}


		for (int k = 0; k < 102; k++) {;

			map[k][0] = 0;
			map[k][1] = 0;
			visited[k] = false;
		}
	}


	return 0;
}