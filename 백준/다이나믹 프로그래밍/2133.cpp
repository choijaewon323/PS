#include <iostream>
using namespace std;

long long dp[31];

int main()
{
	int n;

	cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	
	for (int i = 3; i <= 30; i++)
	{
		if (i % 2 == 1)
		{
			dp[i] = 0;
		}
		else
		{
			long long result = dp[i - 2] * 3;

			for (int j = i - 4; j >= 0; j -= 2)
			{
				result += dp[j] * 2;
			}

			dp[i] = result;
		}
	}

	cout << dp[n] << '\n';

	return 0;
}