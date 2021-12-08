#include <iostream>
using namespace std;
long long dp[30][30];
long long com(int n, int k)
{
	if (n == k)
	{
		return dp[n][k] = 1;
	}
	if (k == 1)
	{
		return dp[n][k] = n;
	}
	if (dp[n][k] != 0)
	{
		return dp[n][k];
	}
	return dp[n][k] = com(n - 1, k) + com(n - 1, k - 1);
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		cout << com(m, n) << '\n';
	}
	return 0;
}