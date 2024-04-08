#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000

int N;
int arr[MAX];
int dp1[MAX];
int dp2[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		int present = arr[i];
		int longest = 0;

		for (int j = 0; j < i; j++) {
			int prev = arr[j];

			if (prev < present) {
				if (dp1[j] > longest) {
					longest = dp1[j];
				}
			}
		}

		dp1[i] = longest + 1;
	}

	for (int i = N - 1; i >= 0; i--) {
		int present = arr[i];
		int longest = 0;

		for (int j = N - 1; j >= i + 1; j--) {
			int right = arr[j];

			if (present > right) {
				if (dp2[j] > longest) {
					longest = dp2[j];
				}
			}
		}
		dp2[i] = longest + 1;
	}

	int answer = -1;
	for (int i = 0; i < N; i++) {
		int result = dp1[i] + dp2[i] - 1;
		answer = max(answer, result);
	}
	cout << answer << '\n';
	
	return 0;
}