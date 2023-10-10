#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n;
pair<int, int> input[100];
int dp[501][501];

int solve(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int result = 0;

	for (int idx = 0; idx < n; idx++) {
		int a = input[idx].first;
		int b = input[idx].second;

		if (a < i && b < j) {
			result = max(result, solve(a, b) + 1);
		}
	}

	return dp[i][j] = result;
}

void init() {
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			dp[i][j] = -1;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		input[i].first = a;
		input[i].second = b;
	}

	init();

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer = max(answer, solve(input[i].first, input[i].second) + 1);
	}

	cout << n - answer << '\n';

	return 0;
}