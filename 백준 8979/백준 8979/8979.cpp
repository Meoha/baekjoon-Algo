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
			//�ٸ� ������ �ݸ޴��� �� ���� �� ���
			if (medal[i][0] > medal[a][0]) {
				nation_rank++;
			}
			//�ݸ޴��� ���� ���
			else if (medal[i][0] == medal[a][0]) {
				//���޴��� ���� ���
				if (medal[i][1] > medal[a][1]) {
					nation_rank++;
				}
				//���޴��� ���� ���
				else if (medal[i][1] == medal[a][1]) {
					//���޴��� ���� ���
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

	//��� ���ϱ�
	ranking(K);

	cout << nation_rank << endl;

	return 0;
}
