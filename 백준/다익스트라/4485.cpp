#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define INF 1000000

int n;
int arr[126][126];
int dy[] = { -1, 1, 0,0 };
int dx[] = { 0, 0, -1, 1 };
int dist[126][126];

void init()
{
	for (int y = 0; y < 126; y++)
	{
		for (int x = 0; x < 126; x++)
		{
			dist[y][x] = 1000000;
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
	priority_queue<pair<int, pair<int, int>>> pq;
	
	dist[1][1] = arr[1][1];
	pq.push(make_pair(-arr[1][1], make_pair(1, 1)));

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
				int nextDist = cost + arr[nextY][nextX];

				if (dist[nextY][nextX] > nextDist)
				{
					dist[nextY][nextX] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(nextY, nextX)));
				}
			}
		}
	}
}

void solution(int);

void input()
{
	int testNum = 1;
	while (1)
	{
		cin >> n;

		if (n == 0)
		{
			break;
		}

		for (int y = 1; y <= n; y++)
		{
			for (int x = 1; x <= n; x++)
			{
				cin >> arr[y][x];
			}
		}

		solution(testNum);
		testNum++;
	}
}

void solution(int testNum)
{
	dijkstra();
	cout << "Problem " << testNum << ": " << dist[n][n] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}