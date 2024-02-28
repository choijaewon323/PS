#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 300

int N;
int stair[MAX + 1];
int dp[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> stair[i];
	}
	dp[1] = stair[1];
	if (N == 1)
	{
		cout << dp[1] << '\n';
		return 0;
	}
	dp[2] = stair[1] + stair[2];
	if (N == 2)
	{
		cout << dp[2] << '\n';
		return 0;
	}
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	for (int i = 4; i <= N; i++)
	{
		dp[i] = max(
			dp[i - 2] + stair[i],
			dp[i - 3] + stair[i - 1] + stair[i]
		);
	}
	cout << dp[N] << '\n';
	return 0;
}