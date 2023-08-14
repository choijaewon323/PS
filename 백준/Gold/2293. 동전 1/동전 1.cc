#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000

int dp[MAX + 1];

int main() {
	int n, k;
	vector<int> coin;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;
		coin.push_back(temp);
	}

	dp[0] = 1;

	for (int i = 0; i < coin.size(); i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k] << '\n';

	return 0;
}