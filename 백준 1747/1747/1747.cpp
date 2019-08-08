#include <iostream>

using namespace std;

int N;
int ans;

//소수인지
bool isPrime(int a) {

	if (a <= 1) {
		return false;
	}

	for (int i = 2; i <= a / 2; i++) {
		if (a % i == 0) {
			return false;
		}
	}

	return true;
}

//팰린드롬 수인지
bool pel(int a) {

		
	int temp_a = a;
	int temp_b = 0;
	int temp_c = 0;

	while (temp_a != 0) {

		temp_b = temp_a % 10;				
		temp_c = temp_c * 10 + temp_b;
		temp_a = temp_a / 10;
	}

	if (a == temp_c) {
			
		return true;
	}
	
	return false;
}


int main() {

	cin >> N;

	if (N >= 1 && N <= 1000000) {

		int ans = N;

		while (1) {
			if (pel(ans)) {
				if (isPrime(ans)) {

					cout << ans << endl;

					break;
				}
			}

			ans++;
		}
	}

	return 0;
}