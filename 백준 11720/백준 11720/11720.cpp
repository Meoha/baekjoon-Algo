#include <iostream>
#include <string>

using namespace std;

int N;
int num[100];
int sum;

int main() {

	cin >> N;

	string s;

	cin >> s;

	for (int n = 0; n < N; n++) {

		int a = 0;

		a = s[n] - '0';

		sum = sum + a;

	}
	

	cout << sum << endl;

	return 0;
}