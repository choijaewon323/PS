#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define INF 20000000

int dist[801];
int n;

vector<pair<int, int>> edges[801];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;

	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int present = pq.top().second;
		pq.pop();

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
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

void init()
{
	for (int i = 0; i < 801; i++)
	{
		dist[i] = INF;
	}
}

int main() 
{
	int e;
	int a, b, c;
	int must1, must2;
	int cost1, cost2;

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}

	cin >> must1 >> must2;

	// 1 -> 2
	cost1 = 0;
	init();
	dijkstra(1);
	cost1 += dist[must1];
	init();
	dijkstra(must1);
	cost1 += dist[must2];
	init();
	dijkstra(must2);
	cost1 += dist[n];

	// 2 -> 1
	cost2 = 0;
	init();
	dijkstra(1);
	cost2 += dist[must2];
	init();
	dijkstra(must2);
	cost2 += dist[must1];
	init();
	dijkstra(must1);
	cost2 += dist[n];

	if (cost1 >= INF && cost2 >= INF)
	{
		cout << -1 << '\n';
		return 0;
	}

	cout << min(cost1, cost2) << '\n';

	return 0;
}