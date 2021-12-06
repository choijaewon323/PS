#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int board[301][301];
int l, resultY, resultX;
int difY[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int difX[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int moveCount[301][301];

int bfs(int firstY, int firstX)
{
	if (firstY == resultY && firstX == resultX)
	{
		return 1;
	}
	queue<pair<int, int>> q;
	moveCount[firstY][firstX] = 1;
	q.push(make_pair(firstY, firstX));
	while (true)
	{
		pair<int, int> present = q.front();
		int y, x;

		for (int i = 0; i < 8; i++)
		{
			y = present.first + difY[i];
			x = present.second + difX[i];

			if ((y >= 0 && y < l) && (x >= 0 && x < l))
			{
				if (y == resultY && x == resultX)
				{
					return moveCount[present.first][present.second] + 1;
				}
				if (moveCount[y][x] == 0)
				{
					q.push(make_pair(y, x));
					moveCount[y][x] = moveCount[present.first][present.second] + 1;
				}
			}
		}

		q.pop();
		if (q.empty())
		{
			break;
		}
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int y, x;
		cin >> l;
		cin >> y >> x;
		cin >> resultY >> resultX;
		cout << bfs(y, x) - 1 << '\n';
		for (int i = 0; i < 301; i++)
		{
			for (int j = 0; j < 301; j++)
			{
				moveCount[i][j] = 0;
			}
		}
	}

	return 0;
}