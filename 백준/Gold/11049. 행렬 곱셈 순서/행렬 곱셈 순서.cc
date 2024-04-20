#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 500

int N;
pair<int, int> matrix[MAX];
int dp[MAX][MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = -1;
		}
	}
}

int solve(int start, int end) {
	if (start == end) {
		return 0;
	}

	if (dp[start][end] != -1) {
		return dp[start][end];
	}

	int result = INT32_MAX;
	for (int i = start; i <= end - 1; i++) {
		result = min(result, solve(start, i) + solve(i + 1, end) 
			+ matrix[start].first 
			* matrix[i].second 
			* matrix[end].second);
	}
	return dp[start][end] = result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		matrix[i] = { a,b };
	}

	int answer = solve(0, N - 1);
	cout << answer << '\n';

	return 0;
}