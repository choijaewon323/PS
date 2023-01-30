#include <iostream>
#include <algorithm>
using namespace std;

int maze[1001][1001];
int memo[1001][1001];
int n, m;
int maxCandy;
int dy[] = { 1, 0, 1 };
int dx[] = { 0, 1, 1 };

int func(int y, int x)
{
	if (y == n && x == m)
	{
		return maze[y][x];
	}

	if (memo[y][x] != -1)
	{
		return memo[y][x];
	}

	int result = -1;

	for (int i = 0; i < 3; i++)
	{
		int tempY = y + dy[i];
		int tempX = x + dx[i];

		if (tempY >= 1 && tempY <= n && tempX >= 1 && tempX <= m)
		{
			result = max(result, func(tempY, tempX));
		}
	}

	return memo[y][x] = maze[y][x] + result;
}

int main()
{
	cin >> n >> m;

	for (int y = 0; y < 1001; y++)
	{
		for (int x = 0; x < 1001; x++)
		{
			memo[y][x] = -1;
		}
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cin >> maze[y][x];
		}
	}

	cout << func(1, 1) << '\n';

	return 0;
}