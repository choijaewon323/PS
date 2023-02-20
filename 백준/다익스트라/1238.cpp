#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1000000001

int n, m, x;

int dist[1001];
int result[1001];
vector<pair<int, int>> edges[1001];

void init()
{
	for (int i = 0; i < 1001; i++)
	{
		dist[i] = INF;
	}
}

void dijkstra(int start, int dest)
{
	init();
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int present = pq.top().second;
		pq.pop();

		if (present == dest)
		{
			return;
		}

		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i].first;
			int nextDist = cost + edges[present][i].second;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

void input()
{
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (i == x)
		{
			result[i] = 0;
		}
		else
		{
			int temp = 0;
			dijkstra(i, x);
			temp += dist[x];
			dijkstra(x, i);
			temp += dist[i];
			result[i] = temp;
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, result[i]);
	}

	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}