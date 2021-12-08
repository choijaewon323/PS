#include <iostream>
using namespace std;
long long dp[1001][1001];
long long com(int n, int k)
{
	if (n == k)
	{
		return dp[n][k] = 1;
	}
	if (k < 0)
	{
		return 0;
	}
	if (k == 1)
	{
		return dp[n][k] = n;
	}
	if (dp[n][k] != 0)
	{
		return dp[n][k];
	}
	return dp[n][k] = (com(n - 1, k) % 10007 + com(n - 1, k - 1) % 10007) % 10007;
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << com(n, k) << '\n';
	return 0;
}