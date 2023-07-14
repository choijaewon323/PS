#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int n, m;
int matrix[300][300];
vector<vector<bool>> visited;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

typedef struct _node
{
	int y;
	int x;
	int minus;
} node;

bool inRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
	{
		return true;
	}

	return false;
}

void melting()
{
	vector<node> nodes;
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int temp = 0;

			for (int i = 0; i < 4; i++)
			{
				int tempY = y + dy[i];
				int tempX = x + dx[i];

				if (inRange(tempY, tempX) && matrix[tempY][tempX] == 0)
				{
					temp++;
				}
			}

			nodes.push_back({ y, x, temp });
		}
	}

	for (auto no : nodes)
	{
		int tempY = no.y;
		int tempX = no.x;

		if (matrix[tempY][tempX] < no.minus)
		{
			matrix[tempY][tempX] = 0;
		}
		else
		{
			matrix[tempY][tempX] -= no.minus;
		}
	}
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = present.first + dy[i];
			int nextX = present.second + dx[i];

			if (inRange(nextY, nextX) && matrix[nextY][nextX] != 0 && !visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				q.push(make_pair(nextY, nextX));
			}
		}
	}
}

bool isAllMelted()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (matrix[y][x])	// not melted
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;

	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> matrix[y][x];
		}
	}

	while (1)
	{
		int temp;

		// before : check all melted
		if (isAllMelted())
		{
			answer = 0;
			break;
		}

		// 1. calculate melting
		melting();
		answer++;

		// 2. calculate lump
		temp = 0;
		visited = vector<vector<bool>>(n, vector<bool>(m, false));

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (matrix[y][x] != 0 && !visited[y][x])
				{
					bfs(y, x);
					temp++;
				}
			}
		}

		if (temp >= 2)
		{
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}