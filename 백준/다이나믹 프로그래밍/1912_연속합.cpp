#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[100001];
int dp[100001];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	int result = -1001;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] > result)
		{
			result = dp[i];
		}
	}
	cout << result << '\n';
	return 0;
}