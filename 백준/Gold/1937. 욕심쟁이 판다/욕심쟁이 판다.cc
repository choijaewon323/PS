#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, result = 1;
int matrix[500][500];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int dp[500][500];

bool inRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
	{
		return true;
	}
	return false;
}

int func(int startY, int startX)
{
	if (dp[startY][startX] != 0)
	{
		return dp[startY][startX];
	}

	dp[startY][startX] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nextY = startY + dy[i];
		int nextX = startX + dx[i];

		if (inRange(nextY, nextX))
		{
			if (matrix[nextY][nextX] > matrix[startY][startX])
			{
				dp[startY][startX] = max(dp[startY][startX], func(nextY, nextX) + 1);
			}
		}
	}

	return dp[startY][startX];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> matrix[y][x];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			result = max(func(y, x), result);
		}
	}

	cout << result << '\n';

	return 0;
}