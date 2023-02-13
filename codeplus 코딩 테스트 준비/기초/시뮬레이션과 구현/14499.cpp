#include <iostream>
using namespace std;

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

int board[20][20];
int dice[7];

int toEast[] = { 0, 4, 2, 1, 6, 5, 3 };
int toWest[] = { 0, 3, 2, 6, 1, 5, 4 };
int toNorth[] = { 0, 5, 1, 3, 4, 6, 2 };
int toSouth[] = { 0, 2, 6, 3, 4, 1, 5 };

void east()
{
	int temp[7];

	for (int i = 1; i <= 6; i++)
	{
		temp[i] = dice[i];
	}

	for (int i = 1; i <= 6; i++)
	{
		dice[i] = temp[toEast[i]];
	}
}

void west()
{
	int temp[7];

	for (int i = 1; i <= 6; i++)
	{
		temp[i] = dice[i];
	}

	for (int i = 1; i <= 6; i++)
	{
		dice[i] = temp[toWest[i]];
	}
}

void north()
{
	int temp[7];

	for (int i = 1; i <= 6; i++)
	{
		temp[i] = dice[i];
	}

	for (int i = 1; i <= 6; i++)
	{
		dice[i] = temp[toNorth[i]];
	}
}

void south()
{
	int temp[7];

	for (int i = 1; i <= 6; i++)
	{
		temp[i] = dice[i];
	}

	for (int i = 1; i <= 6; i++)
	{
		dice[i] = temp[toSouth[i]];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, y, k;

	cin >> n >> m >> y >> x >> k;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> board[y][x];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int direction;
		
		cin >> direction;

		switch (direction)
		{
		case EAST:
			if (x + 1 <= m - 1)
			{
				x++;
				east();

				if (board[y][x] == 0)
				{
					board[y][x] = dice[6];
				}
				else
				{
					dice[6] = board[y][x];
					board[y][x] = 0;
				}

				cout << dice[1] << '\n';
			}
			break;
		case WEST:
			if (x - 1 >= 0)
			{
				x--;
				west();

				if (board[y][x] == 0)
				{
					board[y][x] = dice[6];
				}
				else
				{
					dice[6] = board[y][x];
					board[y][x] = 0;
				}

				cout << dice[1] << '\n';
			}
			break;
		case NORTH:
			if (y - 1 >= 0)
			{
				y--;
				north();

				if (board[y][x] == 0)
				{
					board[y][x] = dice[6];
				}
				else
				{
					dice[6] = board[y][x];
					board[y][x] = 0;
				}

				cout << dice[1] << '\n';
			}
			break;
		case SOUTH:
			if (y + 1 <= n - 1)
			{
				y++;
				south();

				if (board[y][x] == 0)
				{
					board[y][x] = dice[6];
				}
				else
				{
					dice[6] = board[y][x];
					board[y][x] = 0;
				}

				cout << dice[1] << '\n';
			}
			break;
		}
	}

	return 0;
}