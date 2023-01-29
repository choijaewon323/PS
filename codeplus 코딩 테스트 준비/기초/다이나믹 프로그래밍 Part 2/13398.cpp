#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001][2];
int input[100001];

int main()
{
	int n;
	int result;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	if (n == 1)
	{
		cout << input[0] << '\n';
		return 0;
	}

	dp[0][0] = input[0];
	dp[0][1] = input[0];
	
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + input[i], input[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + input[i]);
	}

	result = INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		result = max(result, max(dp[i][0], dp[i][1]));
	}

	cout << result << '\n';

	return 0;
}