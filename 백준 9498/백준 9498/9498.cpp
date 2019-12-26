#include <iostream>

using namespace std;

int main() {

	int A;

	cin >> A;

	if (A >= 90 && A <= 100) {
		cout << "A" << '\n';
	}
	else if (A >= 80 && A <= 89) {
		cout << "B" << '\n';
	}
	else if (A >= 70 && A <= 79) {
		cout << "C" << '\n';
	}
	else if (A >= 60 && A <= 69) {
		cout << "D" << '\n';
	}
	else {
		cout << "F" << '\n';
	}

	return 0;
}