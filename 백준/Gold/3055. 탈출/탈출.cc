#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int r, c;
char matrix[50][50];
int visited[50][50];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

#define WATER 0
#define DOCH 1

typedef struct _node
{
	int y;
	int x;
	int type;
} node;

bool inRange(int y, int x)
{
	if (0 <= y && y < r && 0 <= x && x < c)
	{
		return true;
	}
	return false;
}

int bfs(int startY, int startX, vector<node>& waters)
{
	queue<node> q;

	visited[startY][startX] = 1;

	for (auto& water : waters)
	{
		q.push(water);
	}

	q.push({ startY, startX, DOCH });

	while (!q.empty())
	{
		node present = q.front();
		q.pop();

		if (present.type == DOCH && matrix[present.y][present.x] == 'D')
		{
			return visited[present.y][present.x] - 1;
		}

		if (present.type == WATER)
		{
			for (int i = 0; i < 4; i++)
			{
				int nextY = present.y + dy[i];
				int nextX = present.x + dx[i];

				if (inRange(nextY, nextX) && matrix[nextY][nextX] == '.')
				{
					matrix[nextY][nextX] = '*';
					q.push({ nextY, nextX, WATER });
				}
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int nextY = present.y + dy[i];
				int nextX = present.x + dx[i];

				if (inRange(nextY, nextX) && !visited[nextY][nextX]
					&& matrix[nextY][nextX] == '.' || matrix[nextY][nextX] == 'D')
				{
					visited[nextY][nextX] = visited[present.y][present.x] + 1;
					q.push({ nextY, nextX, DOCH });
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int answer, startY, startX;
	vector<node> waters;

	cin >> r >> c;

	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cin >> matrix[y][x];

			if (matrix[y][x] == '*')
			{
				waters.push_back({ y, x, WATER });
			}
			else if (matrix[y][x] == 'S')
			{
				startY = y;
				startX = x;
			}
		}
	}

	answer = bfs(startY, startX, waters);

	if (answer == -1)
	{
		cout << "KAKTUS" << '\n';
	}
	else
	{
		cout << answer << '\n';
	}

	return 0;
}