#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;

	getline(cin, input);

	int cnt = 0;

	for (int i = 0; i < input.length() - 1; i++) {

		if(input[i] == ' '){
			cnt++;
		}
	}

	if (input[0] == ' ') {
		cnt--;
	}

	if (input[input.length() - 1] == ' ') {
		cnt--;
	}

	cout << cnt + 1 << '\n';

	return 0;
}