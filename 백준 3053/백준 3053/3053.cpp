#include <iostream>

using namespace std;

const double PI = 3.14159265359;

int main() {

	double N;

	cin >> N;

	printf("%.6f\n", PI * N * N);
	printf("%.6f\n", 2.0 * N * N);

	return 0;
}