#include <iostream>

using namespace std;

int N, K;
int medal[1001][3];
int nation_rank = 1;

void ranking(int a) {

	for (int i = 1; i <= N; i++) {
		if (i == a) {
			continue;
		}
		else {
			//다른 국가가 금메달을 더 많이 딴 경우
			if (medal[i][0] > medal[a][0]) {
				nation_rank++;
			}
			//금메달이 같을 경우
			else if (medal[i][0] == medal[a][0]) {
				//은메달이 많을 경우
				if (medal[i][1] > medal[a][1]) {
					nation_rank++;
				}
				//은메달이 같을 경우
				else if (medal[i][1] == medal[a][1]) {
					//동메달이 많을 경우
					if (medal[i][2] > medal[a][2]) {
						nation_rank++;
					}
				}
			}

		}
	}

}

int main() {

	cin >> N >> K;

	for (int n = 1; n <= N; n++) {
		int nation;
		int gold;
		int silver;
		int bronze;

		cin >> nation >> gold >> silver >> bronze;

		medal[nation][0] = gold;
		medal[nation][1] = silver;
		medal[nation][2] = bronze;
	}

	//등수 구하기
	ranking(K);

	cout << nation_rank << endl;

	return 0;
}
