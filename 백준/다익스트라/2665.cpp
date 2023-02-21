#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define INF 100000000

int n;
char maze[51][51];
int mazeToInt[51][51];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int dist[51][51];

void init()
{
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			dist[i][j] = INF;
		}
	}
}

bool inRange(int y, int x)
{
	if (y >= 1 && y <= n && x >= 1 && x <= n)
	{
		return true;
	}
	return false;
}

void dijkstra()
{
	init();
	priority_queue <pair<int, pair<int, int>>> pq;

	dist[1][1] = 0;
	pq.push(make_pair(0, make_pair(1, 1)));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		pair<int, int> present = pq.top().second;
		pq.pop();
	
		if (present.first == n && present.second == n)
		{
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = present.first + dy[i];
			int nextX = present.second + dx[i];

			if (inRange(nextY, nextX))
			{
				int nextDist = cost + mazeToInt[nextY][nextX];

				if (dist[nextY][nextX] > nextDist)
				{
					dist[nextY][nextX] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(nextY, nextX)));
				}
			}
		}
	}
}

void input()
{
	cin >> n;
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> maze[y][x];

			if (maze[y][x] == '0')
			{
				mazeToInt[y][x] = 1;
			}
			else
			{
				mazeToInt[y][x] = 0;
			}
		}
	}
}

void solution()
{
	dijkstra();

	cout << dist[n][n] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}