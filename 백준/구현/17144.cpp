#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define MAX 50

typedef struct _node
{
	int y;
	int x;
	int d;
} node;

int room[MAX + 1][MAX + 1];
int r, c, t;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
vector<int> cleaner;

bool inRange(int y, int x)
{
	if (1 <= y && y <= r && 1 <= x && x <= c)
	{
		return true;
	}
	return false;
}

void func(int y, int x, int d)
{
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (inRange(nextY, nextX) && room[nextY][nextX] != -1)
		{
			cnt++;
			room[nextY][nextX] += d / 5;
		}
	}

	room[y][x] -= (d / 5) * cnt;
}

void spread()
{
	vector<node> dust;

	for (int y = 1; y <= r; y++)
	{
		for (int x = 1; x <= c; x++)
		{
			if (room[y][x] > 0)
			{
				node temp = { y, x, room[y][x] };
				dust.push_back(temp);
			}
		}
	}

	for (auto& i : dust)
	{
		func(i.y, i.x, i.d);
	}
}

void clean()
{
	// upper
	queue<int> q;
	int upperY = cleaner[0];

	for (int x = 2; x <= c; x++)
	{
		q.push(room[upperY][x]);
	}
	for (int y = upperY - 1; y >= 1; y--)
	{
		q.push(room[y][c]);
	}
	for (int x = c - 1; x >= 1; x--)
	{
		q.push(room[1][x]);
	}
	for (int y = 2; y <= upperY - 2; y++)
	{
		q.push(room[y][1]);
	}

	room[upperY][2] = 0;
	for (int x = 3; x <= c; x++)
	{
		int temp = q.front();
		q.pop();

		room[upperY][x] = temp;
	}
	for (int y = upperY - 1; y >= 1; y--)
	{
		int temp = q.front();
		q.pop();

		room[y][c] = temp;
	}
	for (int x = c - 1; x >= 1; x--)
	{
		int temp = q.front();
		q.pop();

		room[1][x] = temp;
	}
	for (int y = 2; y <= upperY - 1; y++)
	{
		int temp = q.front();
		q.pop();

		room[y][1] = temp;
	}

	// lower
	int lowerY = cleaner[1];
	for (int x = 2; x <= c - 1; x++)
	{
		q.push(room[lowerY][x]);
	}
	for (int y = lowerY; y <= r - 1; y++)
	{
		q.push(room[y][c]);
	}
	for (int x = c; x >= 2; x--)
	{
		q.push(room[r][x]);
	}
	for (int y = r; y >= lowerY + 2; y--)
	{
		q.push(room[y][1]);
	}
	room[lowerY][2] = 0;
	for (int x = 3; x <= c - 1; x++)
	{
		int temp = q.front();
		q.pop();

		room[lowerY][x] = temp;
	}
	for (int y = lowerY; y <= r - 1; y++)
	{
		int temp = q.front();
		q.pop();

		room[y][c] = temp;
	}
	for (int x = c; x >= 2; x--)
	{
		int temp = q.front();
		q.pop();

		room[r][x] = temp;
	}
	for (int y = r; y >= lowerY + 1; y--)
	{
		int temp = q.front();
		q.pop();

		room[y][1] = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;

	for (int y = 1; y <= r; y++)
	{
		for (int x = 1; x <= c; x++)
		{
			cin >> room[y][x];

			if (room[y][x] == -1)
			{
				cleaner.push_back(y);
			}
		}
	}

	for (int sec = 1; sec <= t; sec++)
	{
		// clear
		spread();

		clean();
	}

	int result = 0;
	for (int y = 1; y <= r; y++)
	{
		for (int x = 1; x <= c; x++)
		{
			if (room[y][x] > 0)
			{
				result += room[y][x];
			}
		}
	}

	cout << result << '\n';

	return 0;
}