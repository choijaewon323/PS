#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

typedef struct _shark
{
	int y;
	int x;
	int speed;
	int direction;
	int size;
} shark;

typedef struct _coor
{
	int y;
	int x;
	int direction;
} coor;

int r, c, m;
shark board[MAX + 1][MAX + 1];

coor up(int, int, int);
coor down(int, int, int);
coor right(int, int, int);
coor left(int, int, int);

coor up(int y, int x, int speed)
{
	coor result;

	int tempY = y;

	while (true)
	{
		if (speed == 0)
		{
			break;
		}
		if (tempY == 1)
		{
			break;
		}

		speed--;
		tempY--;
	}

	if (speed > 0)
	{
		return down(tempY, x, speed);
	}

	result = { tempY, x, UP };

	return result;
}

coor down(int y, int x, int speed)
{
	coor result;

	int tempY = y;

	while (true)
	{
		if (speed == 0)
		{
			break;
		}
		if (tempY == r)
		{
			break;
		}

		speed--;
		tempY++;
	}

	if (speed > 0)
	{
		return up(tempY, x, speed);
	}

	result = { tempY, x, DOWN };

	return result;
}

coor right(int y, int x, int speed)
{
	coor result;

	int tempX = x;

	while (true)
	{
		if (speed == 0)
		{
			break;
		}
		if (tempX == c)
		{
			break;
		}

		speed--;
		tempX++;
	}

	if (speed > 0)
	{
		return left(y, tempX, speed);
	}

	result = { y, tempX, RIGHT };

	return result;
}

coor left(int y, int x, int speed)
{
	coor result;

	int tempX = x;

	while (true)
	{
		if (speed == 0)
		{
			break;
		}
		if (tempX == 1)
		{
			break;
		}

		speed--;
		tempX--;
	}

	if (speed > 0)
	{
		return right(y, tempX, speed);
	}

	result = { y, tempX, LEFT };

	return result;
}

shark move(shark temp)
{
	int y = temp.y;
	int x = temp.x;
	board[y][x] = { 0,0,0,0,0 };

	int direction = temp.direction;
	coor next;

	switch (direction)
	{
	case UP:
		next = up(y, x, temp.speed);
		break;
	case DOWN:
		next = down(y, x, temp.speed);
		break;
	case RIGHT:
		next = right(y, x, temp.speed);
		break;
	case LEFT:
		next = left(y, x, temp.speed);
		break;
	}

	temp.direction = next.direction;
	temp.y = next.y;
	temp.x = next.x;
	
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c, d, e;

		cin >> a >> b >> c >> d >> e;

		shark temp = { a, b, c, d, e };
		board[a][b] = temp;
	}

	int result = 0;
	// 1. 이동
	for (int sec = 1; sec <= c; sec++)
	{
		// 2. 상어 잡기
		for (int y = 1; y <= r; y++)
		{
			if (board[y][sec].y != 0)
			{
				result += board[y][sec].size;
				board[y][sec] = { 0, 0, 0, 0, 0 };
				break;
			}
		}
		
		vector<shark> temp;
		// 3. 상어 이동
		for (int y = 1; y <= r; y++)
		{
			for (int x = 1; x <= c; x++)
			{
				if (board[y][x].y != 0)
				{
					temp.push_back(move(board[y][x]));
				}
			}
		}

		for (auto i : temp)
		{
			if (board[i.y][i.x].y != 0)
			{
				if (i.size > board[i.y][i.x].size)
				{
					board[i.y][i.x] = i;
				}
			}
			else
			{
				board[i.y][i.x] = i;
			}
		}
	}

	cout << result << '\n';

	return 0;
}