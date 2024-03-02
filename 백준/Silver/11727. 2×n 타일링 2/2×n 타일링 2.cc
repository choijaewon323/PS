#include <iostream>
using namespace std;

#define MAX 1000
#define MOD 10007

int dp[MAX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= MAX; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
	}

	cout << dp[n] << '\n';

	return 0;
}