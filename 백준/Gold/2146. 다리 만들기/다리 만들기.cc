#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int matrix[100][100];
int n;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

vector<vector<int>> dist;

bool inRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
	{
		return true;
	}
	return false;
}

void bfs(int startY, int startX, int island)
{
	queue<pair<int, int>> q;

	matrix[startY][startX] = island;
	q.push({ startY, startX });

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = present.first + dy[i];
			int nextX = present.second + dx[i];

			if (inRange(nextY, nextX) && matrix[nextY][nextX] == 1)
			{
				matrix[nextY][nextX] = island;
				q.push({ nextY, nextX });
			}
		}
	}
}

int bfs2(int startY, int startX, int island)
{
	queue<pair<int, int>> q;

	dist = vector<vector<int>>(n, vector<int>(n, 0));
	dist[startY][startX] = 1;
	q.push({ startY, startX });

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = present.first + dy[i];
			int nextX = present.second + dx[i];

			if (inRange(nextY, nextX) && matrix[nextY][nextX] != 0 &&
				matrix[nextY][nextX] != island)
			{
				return dist[present.first][present.second] - 1;
			}

			if (inRange(nextY, nextX) && dist[nextY][nextX] == 0 &&
				matrix[nextY][nextX] == 0)
			{
				dist[nextY][nextX] = dist[present.first][present.second] + 1;
				q.push({ nextY, nextX });
			}
		}
	}

	return 10001;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int island, answer;

	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> matrix[y][x];
		}
	}

	island = 2;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (matrix[y][x] == 1)
			{
				bfs(y, x, island++);
			}
		}
	}

	answer = 10001;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (matrix[y][x] >= 2)
			{
				bool isEdge = false;

				for (int i = 0; i < 4; i++)
				{
					int tempY = y + dy[i];
					int tempX = x + dx[i];

					if (inRange(tempY, tempX) && matrix[tempY][tempX] == 0)
					{
						isEdge = true;
					}
				}

				if (isEdge)
				{
					answer = min(answer, bfs2(y, x, matrix[y][x]));
				}
			}
		}
	}

	
	cout << answer << '\n';

	return 0;
}