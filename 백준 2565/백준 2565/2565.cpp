#include <iostream>
#include <algorithm>

using namespace std;

int N; //�������� ����
int arr[501];
int dp1[501]; //����
int MAX; //����� �������� �ִ밪
int ans; //�����ϴ� ������ �ִ밪

void sol() {

	//����
	for (int i = 1; i <= MAX; i++) {

		if (arr[i] != -1) {

			dp1[i] = 1;

			for (int j = 1; j < i; j++) {

				if (arr[i] > arr[j] && arr[j] != -1 && dp1[i] < dp1[j] + 1) {

					dp1[i] = dp1[j] + 1;
				}

			}

		}

	}

	for (int i = 1; i <= MAX; i++) {

		ans = max(ans, dp1[i]);

	}

	return;
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	fill(arr, arr + 501, -1);

	for (int i = 0; i < N; i++) {

		int a, b;

		cin >> a >> b;

		MAX = max(MAX, a);

		arr[a] = b;

	}

	//sol
	sol();

	cout << N - ans << '\n';

	return 0;
}