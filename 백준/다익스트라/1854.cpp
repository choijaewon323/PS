#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define INF 10000000

int n, m, k;
vector<pair<int, int>> edges[1001];
priority_queue<int> kth_queue[1001];
int dist[1001];

void init()
{
	for (int i = 0; i < 1001; i++)
	{
		dist[i] = INF;
	}
}

void dijkstra()
{
	init();
	priority_queue<pair<int, int>> pq;

	dist[1] = 0;
	pq.push(make_pair(0, 1));
	kth_queue[1].push(0);

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int present = pq.top().second;
		pq.pop();

		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i].first;
			int nextDist = edges[present][i].second + cost;

			if (kth_queue[next].size() < k)
			{
				kth_queue[next].push(nextDist);
				pq.push(make_pair(-nextDist, next));
			}
			else if (kth_queue[next].top() > nextDist)
			{
				kth_queue[next].pop();
				kth_queue[next].push(nextDist);
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
	}
}

void solution()
{
	dijkstra();

	for (int i = 1; i <= n; i++)
	{
		if (kth_queue[i].size() < k)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << kth_queue[i].top() << '\n';
		}
	}
}

int main()
{
	input();
	solution();

	return 0;
}