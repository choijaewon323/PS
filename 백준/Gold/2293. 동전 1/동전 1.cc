#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coins;
int dp[10000 + 1];
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coins.push_back(tmp);
	}

	sort(coins.begin(), coins.end());

	dp[0] = 1;
	for (int coin : coins) {
		for (int i = coin; i <= k; i++) {
			dp[i] += dp[i - coin];
		}
	}

	cout << dp[k] << '\n';

	return 0;
}