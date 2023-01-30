#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int space[50][50];
int n, m;

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void bfs(vector<pair<int, int>> &shark)
{
	queue<pair<int, int>> q;

	for (auto s : shark)
	{
		q.push(s);
	}

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		int tempY, tempX;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			tempY = temp.first + dy[i];
			tempX = temp.second + dx[i];

			if (tempY >= 0 && tempY < n && tempX >= 0 && tempX < m &&
				space[tempY][tempX] == 0)
			{
				space[tempY][tempX] = space[temp.first][temp.second] + 1;
				q.push(make_pair(tempY, tempX));
			}
		}
	}
}

int main()
{
	vector<pair<int, int>> shark;
	int result;
	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> space[y][x];

			if (space[y][x] == 1)
			{
				shark.push_back(make_pair(y, x));
			}
		}
	}

	bfs(shark);

	result = -1;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			result = max(result, space[y][x]);
		}
	}

	cout << result - 1 << '\n';

	return 0;
}