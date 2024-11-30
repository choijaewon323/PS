#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define IMPOSSIBLE 10001
#define INIT -1

int dp[100001];
vector<int> coins;
int n, k;

void init() {
	for (int i = 0; i <= 10000; i++) {
		dp[i] = INIT;
	}
}

int solve(int num) {
	if (dp[num] != INIT) {
		return dp[num];
	}
	
	int result = IMPOSSIBLE;
	
	for (int coin : coins) {
		if (num - coin >= 0) {
			result = min(result, solve(num - coin) + 1);
		}
	}
	return dp[num] = result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coins.push_back(tmp);
		dp[tmp] = 1;
	}
	
	dp[0] = IMPOSSIBLE;

	int answer = solve(k);

	if (answer == IMPOSSIBLE) {
		cout << -1 << '\n';
	} else {
		cout << answer << '\n';
	}

	return 0;
}