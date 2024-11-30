#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define MAX 500
#define INF 1000000000

int K;
int input[MAX];
pair<int, int> dp[MAX][MAX];

void init() {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			dp[i][j] = { -1, -1 };
		}
	}
}

pair<int, int> solve(int start, int end) {
	if (start == end) {
		return { input[start], 0 };
	}

	if (dp[start][end].first != -1) {
		return dp[start][end];
	}

	pair<int, int> result = { INF, INF };
	for (int i = start; i <= end - 1; i++) {
		pair<int, int> left = solve(start, i);
		pair<int, int> right = solve(i + 1, end);

		int acc = left.first + left.second + right.first + right.second;

		if (result.second > acc) {
			result = { left.first + right.first, acc };
		}
	}
	return dp[start][end] = result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> input[i];
		}

		init();

		cout << solve(0, K - 1).second << '\n';
	}

	return 0;
}