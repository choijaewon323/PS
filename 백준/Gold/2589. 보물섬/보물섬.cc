#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

char matrix[50][50];
vector<vector<int>> visited;
int r, c;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool inRange(int y, int x)
{
	if (0 <= y && y < r && 0 <= x && x < c)
	{
		return true;
	}
	return false;
}

int bfs(int startY, int startX)
{
	int maxResult = -1;
	queue<pair<int, int>> q;

	visited = vector<vector<int>>(r, vector<int>(c, 0));
	q.push({ startY, startX });
	visited[startY][startX] = 1;

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = present.first + dy[i];
			int nextX = present.second + dx[i];

			if (inRange(nextY, nextX) && matrix[nextY][nextX] == 'L'
				&& !visited[nextY][nextX])
			{
				visited[nextY][nextX] = visited[present.first][present.second] + 1;
				q.push({ nextY, nextX });

				maxResult = max(maxResult, visited[nextY][nextX]);
			}
		}
	}

	return maxResult - 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int result;

	cin >> r >> c;

	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cin >> matrix[y][x];
		}
	}

	result = -1;
	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			if (matrix[y][x] == 'L')
			{
				int temp = bfs(y, x);

				if (temp > result)
				{
					result = temp;
				}
			}
		}
	}

	cout << result << '\n';

	return 0;
}