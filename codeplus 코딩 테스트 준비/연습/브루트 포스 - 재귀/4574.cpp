#include <iostream>
using namespace std;

int board[11][11];
bool dominos[10][10];
int n;

const int secY[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9}
};

const int secX[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,2,3,1,2,3,1,2,3},
	{0,4,5,6,4,5,6,4,5,6},
	{0,7,8,9,7,8,9,7,8,9},
	{0,1,2,3,1,2,3,1,2,3},
	{0,4,5,6,4,5,6,4,5,6},
	{0,7,8,9,7,8,9,7,8,9},
	{0,1,2,3,1,2,3,1,2,3},
	{0,4,5,6,4,5,6,4,5,6},
	{0,7,8,9,7,8,9,7,8,9},
};

int getSectionNum(int y, int x)
{
	switch (y)
	{
	case 1:
	case 2:
	case 3:
		switch (x)
		{
		case 1:
		case 2:
		case 3:
			return 1;
		case 4:
		case 5:
		case 6:
			return 2;
		case 7:
		case 8:
		case 9:
			return 3;
		}
	case 4:
	case 5:
	case 6:
		switch (x)
		{
		case 1:
		case 2:
		case 3:
			return 4;
		case 4:
		case 5:
		case 6:
			return 5;
		case 7:
		case 8:
		case 9:
			return 6;
		}
	case 7:
	case 8:
	case 9:
		switch (x)
		{
		case 1:
		case 2:
		case 3:
			return 7;
		case 4:
		case 5:
		case 6:
			return 8;
		case 7:
		case 8:
		case 9:
			return 9;
		}
	}

	return 0;
}

bool checkRow(int y, int x, int num)
{
	for (int i = 1; i <= 9; i++)
	{
		if (board[y][i] == num)
		{
			return false;
		}
	}
	return true;
}

bool checkColumn(int y, int x, int num)
{
	for (int i = 1; i <= 9; i++)
	{
		if (board[i][x] == num)
		{
			return false;
		}
	}
	return true;
}

bool checkSection(int y, int x, int num)
{
	int secNum = getSectionNum(y, x);

	for (int i = 1; i <= 9; i++)
	{
		if (board[secY[secNum][i]][secX[secNum][i]] == num)
		{
			return false;
		}
	}
	return true;
}

bool check(int y, int x, int num)
{
	return checkSection(y, x, num) && checkRow(y, x, num) && checkColumn(y, x, num);
}

bool inRange(int index)
{
	if (index >= 1 && index <= 9)
	{
		return true;
	}
	return false;
}

bool func(int y, int x)
{
	if (inRange(y) && !inRange(x))
	{
		return func(y + 1, 1);
	}

	if (!inRange(y) && !inRange(x))
	{
		return true;
	}

	if (board[y][x] != 0)
	{
		return func(y, x + 1);
	}

	// 가로
	if (board[y][x + 1] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (!dominos[i][j] && check(y, x, i) && check(y, x + 1, j))
				{
					board[y][x] = i;
					board[y][x + 1] = j;
					dominos[i][j] = true;
					dominos[j][i] = true;
					bool result = func(y, x + 1);
					if (result)
					{
						return true;
					}
					board[y][x] = 0;
					board[y][x + 1] = 0;
					dominos[i][j] = false;
					dominos[j][i] = false;
				}
			}
		}
	}

	// 세로
	if (board[y + 1][x] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (!dominos[i][j] && check(y, x, i) && check(y + 1, x, j))
				{
					board[y][x] = i;
					board[y + 1][x] = j;
					dominos[i][j] = true;
					dominos[j][i] = true;
					bool result = func(y, x + 1);
					if (result)
					{
						return true;
					}
					board[y][x] = 0;
					board[y + 1][x] = 0;
					dominos[i][j] = false;
					dominos[j][i] = false;
				}
			}
		}
	}

	return false;
}

void init()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			board[i][j] = 0;
			dominos[i][j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 11; i++)
	{
		board[0][i] = -1;
		board[10][i] = -1;
		board[i][0] = -1;
		board[i][10] = -1;
	}

	int cnt = 1;
	while (1)
	{
		init();
		cin >> n;

		if (n == 0)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			int u, v;
			char lu1, lu2, lv1, lv2;

			cin >> u >> lu1 >> lu2 >> v >> lv1 >> lv2;

			board[lu1 - 'A' + 1][lu2 - '0'] = u;
			board[lv1 - 'A' + 1][lv2 - '0'] = v;
			dominos[u][v] = true;
			dominos[v][u] = true;
		}
		cin.ignore();

		for (int i = 1; i <= 9; i++)
		{
			char c1, c2;

			cin >> c1 >> c2;
			board[c1 - 'A' + 1][c2 - '0'] = i;
		}

		func(1, 1);

		cout << "Puzzle " << cnt << '\n';
		for (int y = 1; y <= 9; y++)
		{
			for (int x = 1; x <= 9; x++)
			{
				cout << board[y][x];
			}
			cout << '\n';
		}
		cnt++;
	}

	return 0;
}