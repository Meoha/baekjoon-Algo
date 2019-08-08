#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int card[4][10];
int temp_card[10];

//ī�� 5���� ��� ���� ���̸鼭 ���ڰ� �������� ��
bool rule1() {

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 5; j++) {
			
			if (card[i][j] == 1 && card[i][j + 1] == 1 && card[i][j + 2] == 1 && card[i][j + 3] == 1 && card[i][j + 4] == 1) {
				
				cout << 900 + j + 4 << endl;

				return true;
			}
		}
	}

	return false;
}

//ī�� 5�� �� 4���� ���ڰ� ���� ��
bool rule2() {

	for (int j = 1; j <= 9; j++) {
		if (card[0][j] == 1 && card[1][j] == 1 && card[2][j] == 1 && card[3][j] == 1) {

			cout << 800 + j << endl;

			return true;
		}
	}

	return false;
}

//ī�� 5�� �� 3���� ���ڰ� ���� ������ 2�嵵 ���ڰ� ���� ��
bool rule3() {

	bool check_2 = false;
	bool check_3 = false;
	int score = 0;

	for (int j = 1; j <= 9; j++) {

		int check = 0;

		for (int i = 0; i < 4; i++) {
			if (card[i][j] == 1) {
				check++;
			}
		}

		if (!check_2 && check == 2) {
			check_2 = true;

			score = score + 700 + j;
		}
		
		if (!check_3 && check == 3) {
			check_3 = true;

			score = score + 10 * j;
		}

		if (check_2 && check_3) {
			cout << score << endl;

			return true;
		}

	}

	return false;
}

//5���� ī�� ������ ��� ���� ��
bool rule4() {

	for (int i = 0; i < 4; i++) {
		int check = 0;

		for (int j = 1; j <= 9; j++) {
			if (card[i][j] == 1) {
				check++;
			}

			if (check == 5) {
				cout << 600 + j << endl;

				return true;
			}

		}
	}

	return false;
}

//ī�� 5���� ���ڰ� �������� ��
bool rule5() {

	for (int t = 1; t <= 5; t++) {
		if (temp_card[t] > 1) {
			return false;
		}
		if (temp_card[t] == 1 && temp_card[t + 1] == 1 && temp_card[t + 2] == 1 && temp_card[t + 3] == 1 && temp_card[t + 4] == 1) {

			cout << 500 + t + 4 << endl;

			return true;
		}

	}

	return false;
}

//ī�� 5�� �� 3���� ���ڰ� ���� ��
bool rule6() {

	for (int t = 1; t <= 9; t++) {
		if (temp_card[t] == 3) {

			cout << 400 + t << endl;

			return true;
		}
	}

	return false;
}

//ī�� 5�� �� 2���� ���ڰ� ���� �� �ٸ� 2���� ���ڰ� ���� ��
bool rule7() {

	int score = 0;
	int check = 0;

	for (int t = 1; t <= 9; t++) {

		if (check == 0) {
			if (temp_card[t] == 2) {
				score = score + t + 300;
				check++;
			}
		}
		else if (check == 1) {
			if (temp_card[t] == 2) {
				score = score + t * 10;
				
				cout << score << endl;
				return true;
			}
		}

	}

	return false;
}

//ī�� 5�� �� 2���� ���ڰ� ���� ��
bool rule8() {
	
	for (int t = 1; t <= 9; t++) {

		if (temp_card[t] == 2) {
			cout << 200 + t << endl;

			return true;
		}
	}

	return false;
}

//���� � ��쿡�� �ش����� ���� ��
bool rule9() {
	for (int t = 9; t >= 1; t--) {

		if (temp_card[t] != 0) {
			cout << 100 + t << endl;

			return true;
		}
	}

	return false;
}

int main() {

	for (int i = 0; i < 5; i++) {
		char color;
		int num;

		scanf(" %c %d", &color, &num);

		if (color == 'R') {
			card[0][num] = 1;
		}
		else if (color == 'B') {
			card[1][num] = 1;
		}
		else if (color == 'Y') {
			card[2][num] = 1;
		}
		else if (color == 'G') {
			card[3][num] = 1;
		}

	}

	//���� ���

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 9; j++) {
			if (card[i][j] == 1) {
				temp_card[j]++;
			}
		}
	}

	if (rule1()) {
		
	}
	else if (rule2()) {

	}
	else if (rule3()) {

	}
	else if (rule4()) {

	}
	else if (rule5()) {

	}
	else if (rule6()) {

	}
	else if (rule7()) {

	}
	else if (rule8()) {

	}
	else if (rule9()) {

	}
	return 0;
}