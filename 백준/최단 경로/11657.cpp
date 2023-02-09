#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INFINITY INT64_MAX / 2

vector<pair<int, int>> edges[501];
long long dist[501];
int n, m;

void init()
{
	for (int i = 0; i < 501; i++)
	{
		dist[i] = INFINITY;
	}
}

bool bellmanFord(int start)
{
	for (int iter = 0; iter < n; iter++)
	{
		for (int present = 1; present <= n; present++)
		{
			for (int i = 0; i < edges[present].size(); i++)
			{
				int next = edges[present][i].first;
				int cost = edges[present][i].second;

				if (dist[present] == INFINITY)
				{
					continue;
				}

				if (dist[next] > dist[present] + cost)
				{
					dist[next] = dist[present] + cost;
				}
			}
		}
	}

	for (int present = 1; present <= n; present++)
	{
		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i].first;
			int cost = edges[present][i].second;

			if (dist[present] == INFINITY)
			{
				continue;
			}

			if (dist[next] > dist[present] + cost)
			{
				return false;
			}
		}
	}
	
	return true;
}

int main()
{
	bool result;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		
		cin >> a >> b >> c;

		edges[a].push_back(make_pair(b, c));
	}

	init();
	dist[1] = 0;
	result = bellmanFord(1);

	if (!result)
	{
		cout << -1 << '\n';
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] >= INFINITY)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dist[i] << '\n';
			}
		}
	}

	return 0;
}