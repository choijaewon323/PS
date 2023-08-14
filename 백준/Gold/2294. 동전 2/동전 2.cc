#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

int dp[MAX + 1];

void init() {
	for (int i = 0; i < MAX + 1; i++) {
		dp[i] = MAX;
	}
}

int main() {
	int n, k;
	vector<int> coin;
	cin >> n >> k;

	init();

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coin.push_back(temp);
		dp[temp] = 1;
	}

	for (int i = 1; i < MAX + 1; i++) {
		for (int c : coin) {
			int prev = i - c;
			if (prev <= 0) {
				continue;
			}
			dp[i] = min(dp[prev] + 1, dp[i]);
		}
	}

	if (dp[k] == MAX) {
		cout << -1 << '\n';

		return 0;
	}
	cout << dp[k] << '\n';

	return 0;
}