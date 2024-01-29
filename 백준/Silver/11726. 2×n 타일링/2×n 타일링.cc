#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>

using namespace std;

#define MAX 1001
#define MOD 10007

int dp[MAX + 1];

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= MAX; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	cout << dp[n + 1] << '\n';

	return 0;
}