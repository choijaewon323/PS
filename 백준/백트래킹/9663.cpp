#include <iostream>
using namespace std;

int n;
int board[15][15];
int result;

void queenOn(int y, int x)
{
	board[y][x]++;
	// 가로
	for (int i = 0; i < n; i++)
	{
		if (i == x)
		{
			continue;
		}

		board[y][i]++;
	}

	// 세로
	for (int i = 0; i < n; i++)
	{
		if (i == y)
		{
			continue;
		}
		board[i][x]++;
	}

	// 대각선
	int tempY = y;
	int tempX = x;

	tempY--;
	tempX--;
	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]++;
		tempY--;
		tempX--;
	}

	tempY = y; tempX = x;
	tempY++;
	tempX--;

	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]++;
		tempY++;
		tempX--;
	}

	tempY = y; tempX = x;
	tempY++;
	tempX++;
	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]++;
		tempY++;
		tempX++;
	}

	tempY = y; tempX = x;
	tempY--;
	tempX++;
	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]++;
		tempY--;
		tempX++;
	}
}

void queenOff(int y, int x)
{
	board[y][x]--;
	// 가로
	for (int i = 0; i < n; i++)
	{
		if (i == x)
		{
			continue;
		}

		board[y][i]--;
	}

	// 세로
	for (int i = 0; i < n; i++)
	{
		if (i == y)
		{
			continue;
		}
		board[i][x]--;
	}

	// 대각선
	int tempY = y;
	int tempX = x;

	tempY--;
	tempX--;
	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]--;
		tempY--;
		tempX--;
	}

	tempY = y; tempX = x;
	tempY++;
	tempX--;

	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]--;
		tempY++;
		tempX--;
	}

	tempY = y; tempX = x;
	tempY++;
	tempX++;
	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]--;
		tempY++;
		tempX++;
	}

	tempY = y; tempX = x;
	tempY--;
	tempX++;
	while (1)
	{
		if (tempY < 0 || tempY > n || tempX < 0 || tempX > n)
		{
			break;
		}
		board[tempY][tempX]--;
		tempY--;
		tempX++;
	}
}

void func(int y, int x, int rest)
{
	if (rest == 0)
	{
		result++;
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (board[y][i] == 0)
		{
			queenOn(y, i);
			func(y + 1, i, rest - 1);
			queenOff(y, i);
		}
	}
}

int main()
{
	cin >> n;

	func(0, 0, n);

	cout << result << '\n';

	return 0;
}