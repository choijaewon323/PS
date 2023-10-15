#include <iostream>
#include <algorithm>

using namespace std;

int N;
int r[500];
int c[500];

int dp[500][500];

int solve(int i, int j) {
	if (i == j) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int result = -1;
	for (int k = i; k <= j - 1; k++) {
		int cal = solve(i, k) + solve(k + 1, j) + r[i] * c[k] * c[j];

		if (result == -1) {
			result = cal;
		}
		else {
			result = min(result, cal);
		}
	}

	return dp[i][j] = result;
}

void init() {
	for (int y = 0; y < 500; y++) {
		for (int x = 0; x < 500; x++) {
			dp[y][x] = -1;
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> r[i] >> c[i];
	}

	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}

	if (N == 2) {
		cout << r[0] * r[1] << '\n';
		return 0;
	}

	init();

	cout << solve(0, N - 1) << '\n';

	return 0;
}