#include <iostream>
using namespace std;

#define RIGHT 1
#define DOWN 2

int board[101][101];
int n, l;
bool ramp[101][101];

// 한줄마다의 가능성
bool isPossible(int startY, int startX, int endY, int endX, int direction)
{
	if (direction == RIGHT)
	{
		for (int i = startX; i <= endX; i++)
		{
			if (i == endX)
			{
				continue;
			}
			int present = board[startY][i];
			int next = board[startY][i + 1];

			// 다음 칸이 더 높을때
			if (present < next)
			{
				// 한칸 차이보다 많이 날때
				if (next > present + 1)
				{
					return false;
				}

				for (int j = i; j > i - l; j--)
				{
					if (j < 1)
					{
						return false;
					}

					if (board[startY][j] != present)
					{
						return false;
					}

					if (ramp[startY][j])
					{
						return false;
					}
				}

				// 조건 만족
				for (int j = i; j > i - l; j--)
				{
					ramp[startY][j] = true;
				}
			}
			else if (present > next)
			{
				if (present > next + 1)
				{
					return false;
				}

				for (int j = i + 1; j < i + 1 + l; j++)
				{
					if (j > n)
					{
						return false;
					}

					if (board[startY][j] != next)
					{
						return false;
					}

					if (ramp[startY][j])
					{
						return false;
					}
				}

				// 조건 만족
				for (int j = i + 1; j < i + 1 + l; j++)
				{
					ramp[startY][j] = true;
				}
			}
		}
	}
	else
	{
		for (int i = startY; i <= endY; i++)
		{
			if (i == endY)
			{
				continue;
			}
			int present = board[i][startX];
			int next = board[i + 1][startX];

			// 다음 칸이 더 높을때
			if (present < next)
			{
				// 한칸 차이보다 많이 날때
				if (next > present + 1)
				{
					return false;
				}

				for (int j = i; j > i - l; j--)
				{
					if (j < 1)
					{
						return false;
					}

					if (board[j][startX] != present)
					{
						return false;
					}

					if (ramp[j][startX])
					{
						return false;
					}
				}

				// 조건 만족
				for (int j = i; j > i - l; j--)
				{
					ramp[j][startX] = true;
				}
			}
			else if (present > next)
			{
				if (present > next + 1)
				{
					return false;
				}

				for (int j = i + 1; j < i + 1 + l; j++)
				{
					if (j > n)
					{
						return false;
					}

					if (board[j][startX] != next)
					{
						return false;
					}

					if (ramp[j][startX])
					{
						return false;
					}
				}

				// 조건 만족
				for (int j = i + 1; j < i + 1 + l; j++)
				{
					ramp[j][startX] = true;
				}
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;

	cin >> n >> l;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int x = 1; x <= n; x++)
	{
		bool funcResult;

		funcResult = isPossible(1, x, n, x, DOWN);

		if (funcResult)
		{
			result++;
		}
		for (int temp = 1; temp <= n; temp++)
		{
			ramp[temp][x] = false;
		}
	}

	for (int y = 1; y <= n; y++)
	{
		bool funcResult;

		funcResult = isPossible(y, 1, y, n, RIGHT);
		if (funcResult)
		{
			result++;
		}
		for (int temp = 1; temp <= n; temp++)
		{
			ramp[y][temp] = false;
		}
	}

	cout << result << '\n';
	return 0;
}