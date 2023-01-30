#include <iostream>
#include <algorithm>
using namespace std;

int maze[1000];
int memo[1000]; 
int n;

int func(int x)
{
	if (x >= n)
	{
		return -1;
	}

	if (x == n - 1)
	{
		return 0;
	}

	if (memo[x] != -2)
	{
		return memo[x];
	}

	int a = maze[x];
	int ret = INT32_MAX;

	for (int i = x + 1; i <= x + a; i++)
	{
		int temp = func(i);

		if (temp == -1)
		{
			continue;
		}
		else
		{
			ret = min(ret, temp);
		}
	}
	
	if (ret == INT32_MAX)
	{
		return memo[x] = -1;
	}
	else
	{
		return memo[x] = ret + 1;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < 1000; i++)
	{
		memo[i] = -2;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> maze[i];
	}

	cout << func(0) << '\n';

	return 0;
}