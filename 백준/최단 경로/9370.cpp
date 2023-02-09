#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 50000001

vector<pair<int, int>> edges[2001];
vector<int> candidates;
int dist[2001];

bool compare(pair<int, int> &left, pair<int, int> &right)
{
	return left.second < right.second;
}

void initAll()
{
	for (int i = 0; i < 2001; i++)
	{
		edges[i].clear();
	}
	candidates.clear();
}

void init()
{
	for (int i = 0; i < 2001; i++)
	{
		dist[i] = INF;
	}
}

void dijkstra(int start);

int resultFunc(int start, int must1, int must2, int end)
{
	int cost = 0;
	
	init();
	dijkstra(start);
	cost += dist[must1];
	
	init();
	dijkstra(must1);
	cost += dist[must2];

	init();
	dijkstra(must2);
	cost += dist[end];

	return cost;
}

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
			int nextCost = cost + edges[present][i].second;

			if (dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}
}

int main()
{
	int testNum;

	cin >> testNum;

	for (int test = 0; test < testNum; test++)
	{
		vector<int> results;
		int n, m, t;
		int s, g, h;
		int minAns;

		initAll();

		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 0; i < m; i++)
		{
			int a, b, d;

			cin >> a >> b >> d;
			edges[a].push_back(make_pair(b, d));
			edges[b].push_back(make_pair(a, d));
		}

		for (int i = 0; i < t; i++)
		{
			int x;

			cin >> x;
			candidates.push_back(x);
		}

		for (auto can : candidates)
		{
			int straight;
			int cost1 = 0, cost2 = 0;
			
			init();
			dijkstra(s);
			straight = dist[can];
			cost1 = resultFunc(s, g, h, can);
			cost2 = resultFunc(s, h, g, can);

			if (cost1 >= INF && cost2 >= INF)
			{
				continue;
			}
			if (min(cost1, cost2) > straight)
			{
				continue;
			}
			results.push_back(can);
		}

		sort(results.begin(), results.end());

		for (auto result : results)
		{
			cout << result << " ";
		}
		cout << '\n';
	}

	return 0;
}