#include <iostream>
#include <algorithm>
using namespace std;

int paper[102][102];

int n, m;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int func(int highest)
{
	int result, tempY, tempX;

	result = 0;

	for (int high = 0; high < highest; high++)
	{
		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= m; x++)
			{
				if (paper[y][x] > 0)
				{
					for (int i = 0; i < 4; i++)
					{
						tempY = y + dy[i];
						tempX = x + dx[i];

						if (paper[tempY][tempX] <= 0)
						{
							result++;
						}
					}
				}
			}
		}

		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= m; x++)
			{
				paper[y][x]--;
			}
		}
	}

	return result;
}

int main()
{
	int result, highest;
	cin >> n >> m;

	result = 0;
	highest = -1;
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cin >> paper[y][x];
			if (paper[y][x] > 0)
			{
				result++;
			}
			highest = max(highest, paper[y][x]);
		}
	}
	
	result = result * 2;

	result += func(highest);

	cout << result << '\n';

	return 0;
}