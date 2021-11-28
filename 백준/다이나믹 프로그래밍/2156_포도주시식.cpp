#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long wines[10001];
long long dp[10001];
int main() 
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wines[i];
	}
	dp[1] = wines[1];
	dp[2] = wines[1] + wines[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(max(dp[i - 3] + wines[i - 1], dp[i - 2]) + wines[i], dp[i - 1]);
	}
	cout << dp[n] << '\n';
	return 0;
}