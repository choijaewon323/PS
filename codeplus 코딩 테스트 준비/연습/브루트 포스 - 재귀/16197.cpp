#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;
char board[23][23];
vector<pair<int, int>> coin;
int result = 33;

bool inRange(int y, int x)
{
	if (y >= 1 && y <= n && x >= 1 && x <= m)
	{
		return true;
	}
	return false;
}

void func(int y1, int x1, int y2, int x2, int count)
{
	if (count > 10)
	{
		return;
	}
	if (!inRange(y1, x1) && !inRange(y2, x2))
	{
		return;
	}
	else if (!inRange(y1, x1) && inRange(y2, x2) ||
		inRange(y1,x1) && !inRange(y2, x2))
	{
		if (count > 10)
		{
			return;
		}
		else
		{
			result = min(result, count);
			return;
		}
	}

	int dy[4] = { 0, 0, -1, 1 };
	int dx[4] = { -1, 1, 0, 0 };

	for (int i = 0; i < 4; i++)
	{
		int tempY1 = y1 + dy[i];
		int tempX1 = x1 + dx[i];
		int tempY2 = y2 + dy[i];
		int tempX2 = x2 + dx[i];

		if (board[tempY1][tempX1] != '#' && board[tempY2][tempX2] != '#')
		{
			func(tempY1, tempX1, tempY2, tempX2, count + 1);
		}
		else if (board[tempY1][tempX1] == '#' && board[tempY2][tempX2] != '#')
		{
			func(y1, x1, tempY2, tempX2, count + 1);
		}
		else if (board[tempY1][tempX1] != '#' && board[tempY2][tempX2] == '#')
		{
			func(tempY1, tempX1, y2, x2, count + 1);
		}
	}
}

int main()
{
	for (int y = 0; y < 23; y++)
	{
		for (int x = 0; x < 23; x++)
		{
			board[y][x] = '.';
		}
	}

	cin >> n >> m;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			char temp;

			cin >> temp;
			board[y][x] = temp;

			if (temp == 'o')
			{
				coin.push_back(make_pair(y, x));
			}
		}
	}

	if (coin.size() == 1)
	{
		pair<int, int> temp = coin.back();
		coin.push_back(temp);
	}

	func(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0);

	if (result == 33)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << result << '\n';
	}

	return 0;
}