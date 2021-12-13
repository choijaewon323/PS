#include <iostream>
using namespace std;
int n;
int dp[1001][20];
int func(int index, int num)
{
	if (index == n)
	{
		return 1;
	}
	if (dp[index][num] != 0)
	{
		return dp[index][num];
	}
	long long result = 0;
	for (int i = num; i <= 9; i++)
	{
		result += func(index + 1, i);
	}
	result %= 10007;
	dp[index][num] = result;
	return result;
}
int main()
{
	cin >> n;
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += func(1, i);
	}
	cout << result % 10007 << '\n';
	return 0;
}