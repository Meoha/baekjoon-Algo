#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;

	for (int i = 0; i < record.size(); i++) {
		vector<string> record_temp;
		string temp;

		for (int j = 0; j < record[i].length(); j++) {

			if (record[i][j] != ' ') {
				temp = temp + record[i][j];
			}
			else if (record[i][j] == ' ') {
				record_temp.push_back(temp);
				temp = "";
			}

		}
		record_temp.push_back(temp);

		if (record_temp[0] == "Change") {
			m[record_temp[1]] = record_temp[2];
		}
		else if (record_temp[0] == "Enter") {
			m[record_temp[1]] = record_temp[2];
		}

	}

	for (int i = 0; i < record.size(); i++) {
		vector<string> record_temp;
		string temp;

		for (int j = 0; j < record[i].length(); j++) {


			if (record[i][j] != ' ') {
				temp = temp + record[i][j];
			}
			else {
				record_temp.push_back(temp);
				temp = "";
			}

		}
		record_temp.push_back(temp);

		if (record_temp[0] == "Enter") {
			answer.push_back(m[record_temp[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (record_temp[0] == "Leave") {
			answer.push_back(m[record_temp[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}

	return answer;
}