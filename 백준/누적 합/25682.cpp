#include <iostream>
#include <algorithm>
using namespace std;

#define BLACK 0
#define WHITE 1

char board[2001][2001];
int isCorrect[2001][2001];

void check(int n, int m, int color)
{
	if (color == BLACK)
	{
		// temp = È¦¼öÇà 1, Â¦¼öÇà 0
		for (int y = 1; y <= n; y++)
		{
			int temp = y % 2;
			for (int x = 1; x <= m; x++)
			{
				switch (temp)
				{
				case 1:	// È¦¼öÇà
					if (x % 2 == 1)	// È¦¼ö¿­
					{
						if (board[y][x] == 'W')
						{
							isCorrect[y][x] = 1;
						}
					}
					else	// Â¦¼ö¿­
					{
						if (board[y][x] == 'B')
						{
							isCorrect[y][x] = 1;
						}
					}
					break;
				case 0:	// Â¦¼öÇà
					if (x % 2 == 1)	// È¦¼ö¿­
					{
						if (board[y][x] == 'B')
						{
							isCorrect[y][x] = 1;
						}
					}
					else	// Â¦¼ö¿­
					{
						if (board[y][x] == 'W')
						{
							isCorrect[y][x] = 1;
						}
					}
					break;
				}
			}
		}
	}
	else
	{
		// temp = È¦¼öÇà 1, Â¦¼öÇà 0
		for (int y = 1; y <= n; y++)
		{
			int temp = y % 2;
			for (int x = 1; x <= m; x++)
			{
				switch (temp)
				{
				case 1:	// È¦¼öÇà
					if (x % 2 == 1)	// È¦¼ö¿­
					{
						if (board[y][x] == 'B')
						{
							isCorrect[y][x] = 1;
						}
					}
					else	// Â¦¼ö¿­
					{
						if (board[y][x] == 'W')
						{
							isCorrect[y][x] = 1;
						}
					}
					break;
				case 0:	// Â¦¼öÇà
					if (x % 2 == 1)	// È¦¼ö¿­
					{
						if (board[y][x] == 'W')
						{
							isCorrect[y][x] = 1;
						}
					}
					else	// Â¦¼ö¿­
					{
						if (board[y][x] == 'B')
						{
							isCorrect[y][x] = 1;
						}
					}
					break;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	int result = INT32_MAX;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}

	check(n, m, BLACK);

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			isCorrect[y][x] += isCorrect[y][x - 1] + isCorrect[y - 1][x] - isCorrect[y - 1][x - 1];
		}
	}

	for (int y = k; y <= n; y++)
	{
		for (int x = k; x <= m; x++)
		{
			int rangeSum = isCorrect[y][x] - isCorrect[y - k][x] - isCorrect[y][x - k] + isCorrect[y - k][x - k];
			result = min(result, rangeSum);
		}
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			isCorrect[y][x] = 0;
		}
	}

	check(n, m, WHITE);

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			isCorrect[y][x] += isCorrect[y][x - 1] + isCorrect[y - 1][x] - isCorrect[y - 1][x - 1];
		}
	}

	for (int y = k; y <= n; y++)
	{
		for (int x = k; x <= m; x++)
		{
			int rangeSum = isCorrect[y][x] - isCorrect[y - k][x] - isCorrect[y][x - k] + isCorrect[y - k][x - k];
			result = min(result, rangeSum);
		}
	}

	cout << result << '\n';

	return 0;
}