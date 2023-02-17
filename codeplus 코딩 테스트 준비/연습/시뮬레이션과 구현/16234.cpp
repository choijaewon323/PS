#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int land[50][50];
int n, l, r;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
bool visited[50][50];

typedef struct _node
{
	int people;
	int blockCount;
	vector<pair<int, int>> blocks;
} node;

vector<node> cor;

bool inRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < n)
	{
		return true;
	}
	return false;
}

bool diff(int a, int b)
{
	int d = abs(a - b);

	if (d >= l && d <= r)
	{
		return true;
	}
	return false;
}

node bfs(int startY, int startX)
{
	node result;
	queue<pair<int, int>> q;

	visited[startY][startX] = true;
	q.push(make_pair(startY, startX));
	result.people = land[startY][startX];
	result.blockCount = 1;
	result.blocks.push_back(make_pair(startY, startX));

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = present.first + dy[i];
			int nextX = present.second + dx[i];

			if (inRange(nextY, nextX) && !visited[nextY][nextX] &&
				diff(land[present.first][present.second], land[nextY][nextX]))
			{
				visited[nextY][nextX] = true;
				q.push(make_pair(nextY, nextX));
				result.people += land[nextY][nextX];
				result.blockCount++;
				result.blocks.push_back(make_pair(nextY, nextX));
			}
		}
	}

	return result;
}

void init()
{
	cor.clear();
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			visited[y][x] = false;
		}
	}
}

int main()
{
	cin >> n >> l >> r;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> land[y][x];
		}
	}

	int days = 0;
	while (1)
	{
		init();

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (!visited[y][x])
				{
					node temp = bfs(y, x);
					cor.push_back(temp);
				}
			}
		}

		if (cor.size() == n * n)
		{
			break;
		}
		else
		{
			for (int i = 0; i < cor.size(); i++)
			{
				int res = cor[i].people / cor[i].blockCount;
				
				for (auto b : cor[i].blocks)
				{
					land[b.first][b.second] = res;
				}
			}
			days++;
		}
	}

	cout << days << '\n';

	return 0;
}