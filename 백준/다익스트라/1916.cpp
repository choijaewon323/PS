#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int n, m, start, dest;
vector<pair<int, int>> edges[1001];

#define INF 100000000

int dist[1001];

void init()
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
}

void dijkstra()
{
	priority_queue<pair<int, int>> q;
	dist[start] = 0;

	q.push(make_pair(0, start));

	while (!q.empty())
	{
		int cost = -q.top().first;
		int present = q.top().second;
		q.pop();

		if (present == dest)
		{
			return;
		}

		if (dist[present] < cost)
		{
			continue;
		}

		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i].first;
			int nextDist = cost + edges[present][i].second;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				q.push(make_pair(-nextDist, next));
			}
		}
	}
}

void input()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
	}
	cin >> start >> dest;
}

void solution()
{
	init();
	dijkstra();

	cout << dist[dest] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}