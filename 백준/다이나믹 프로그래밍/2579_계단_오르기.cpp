#include <iostream>
#include <algorithm>
using namespace std;

int stairsScore[301];
int dp[301];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> stairsScore[i];
	}
	
	dp[1] = stairsScore[1];
	dp[2] = max(stairsScore[1] + stairsScore[2], stairsScore[2]);
	dp[3] = max(stairsScore[1] + stairsScore[3], stairsScore[2] + stairsScore[3]);

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + stairsScore[i], dp[i - 3] + stairsScore[i - 1] + stairsScore[i]);
	}

	cout << dp[n] << '\n';

	return 0;
}