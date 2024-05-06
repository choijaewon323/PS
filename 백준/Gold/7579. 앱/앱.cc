#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int N, M;
int mem[MAX + 1];
int cost[MAX + 1];
int dp[MAX + 1][10001];
int all;

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> mem[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		all += cost[i];
	}
}

int solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= all; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= all; i++) {
		if (dp[N][i] >= M) {
			return i;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}
