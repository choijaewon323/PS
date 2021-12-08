#include <iostream>
using namespace std;
int seq[1001];
int dp[1001];
int dp1[1001];
int main()
{
	int n, temp = 0;;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> seq[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= i - 1; j++)
		{
			if (seq[j] < seq[i])
			{
				if (dp[j] > temp)
				{
					temp = dp[j];
				}
			}
		}
		dp[i] = temp + 1;
	}
	dp1[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		int temp = 0;
		for (int j = n; j >= i + 1; j--)
		{
			if (seq[j] < seq[i])
			{
				if (dp1[j] > temp)
				{
					temp = dp1[j];
				}
			}
		}
		dp1[i] = temp + 1;
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (result < (dp[i] + dp1[i]))
		{
			result = (dp[i] + dp1[i]);
		}
	}
	cout << result - 1 << '\n';
	return 0;
}