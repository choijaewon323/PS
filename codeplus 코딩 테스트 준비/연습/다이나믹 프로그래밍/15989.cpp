#include <iostream>
using namespace std;

int memo[10001][4];
int n;

int func(int num, int lastUsed)
{
	if (num == 1)
	{
		return 1;
	}
	if (num == 2)
	{
		if (lastUsed >= 2)
		{
			return 2;
		}
		if (lastUsed == 1)
		{
			return 1;
		}
	}
	if (num == 3)
	{
		if (lastUsed == 3)
		{
			return 3;
		}
		if (lastUsed == 2)
		{
			return 2;
		}
		if (lastUsed == 1)
		{
			return 1;
		}
	}

	if (memo[num][lastUsed] != 0)
	{
		return memo[num][lastUsed];
	}

	int result = 0;

	for (int i = lastUsed; i >= 1; i--)
	{
		result += func(num - i, i);
	}

	return memo[num][lastUsed] = result;
}

int main()
{
	int t;

	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int result;
		for (int i = 0; i < 10001; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				memo[i][j] = 0;
			}
		}

		cin >> n;
		result = func(n, 3);
		cout << result << '\n';
	}

	return 0;
}