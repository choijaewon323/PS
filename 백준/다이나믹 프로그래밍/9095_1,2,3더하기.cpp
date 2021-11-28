#include <iostream>
using namespace std;
int dp[11];
int func(int number)
{
	if (number == 1)
	{
		return 1;
	}
	if (number == 2)
	{
		return 2;
	}
	if (number == 3)
	{
		return 4;
	}
	if (dp[number] != 0)
	{
		return dp[number];
	}
	return dp[number] = func(number - 1) + func(number - 2) +func(number - 3);
}
int main()
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << func(n) << '\n';
	}
	return 0;
}