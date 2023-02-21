#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n, m;
int source, dest;
vector<pair<int, int>> edges[1001];
int dist[1001];
int prevNode[1001];

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

	dist[source] = 0;
	pq.push(make_pair(0, source));

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
				prevNode[next] = present;
				pq.push(make_pair(-nextDist, next));
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

	cin >> source >> dest;
}

void solution()
{
	dijkstra();
	cout << dist[dest] << '\n';
	vector<int> route;
	route.push_back(dest);
	while (1)
	{
		int temp = route.back();

		if (temp == source)
		{
			break;
		}
		route.push_back(prevNode[temp]);
	}
	reverse(route.begin(), route.end());

	cout << route.size() << '\n';
	for (auto r : route)
	{
		cout << r << " ";
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	return 0;
}