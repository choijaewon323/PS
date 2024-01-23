#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 500

int dp[MAX][MAX];
int triangle[MAX][MAX];
int n;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
}

int solve(const int y, const int x) {
	if (y == n - 1) {
		return triangle[y][x];
	}

	if (dp[y][x] != 0) {
		return dp[y][x];
	}

	int result = triangle[y][x];
	
	result += max(solve(y + 1, x), solve(y + 1, x + 1));

	return dp[y][x] = result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve(0, 0) << '\n';

	return 0;
}