#include <iostream>
using namespace std;

int dp[46][2];

int main() {
	int k;
	cin >> k;

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	if (k >= 2) {
		for (int i = 2; i <= k; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		}
	}

	cout << dp[k][0] << " " << dp[k][1] << '\n';

	return 0;
}