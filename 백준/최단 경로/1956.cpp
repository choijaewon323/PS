#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 1596000000ll

typedef long long ll;

vector<pair<int, int>> edges[159601];
ll dist[401][401];
int v;

void init()
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int present = 1; present <= v; present++)
	{
		for (int i = 0; i < edges[present].size(); i++)
		{
			dist[present][edges[present][i].first] = edges[present][i].second;
		}
	}
}

void floyd_warshall()
{
	for (int k = 1; k < v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main()
{
	int e;
	ll result = INT32_MAX;

	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		
		cin >> a >> b >> c;

		edges[a].push_back(make_pair(b, c));
	}

	init();
	floyd_warshall();

	for (int i = 1; i <= v; i++)
	{
		if (dist[i][i] >= INF)
		{
			continue;
		}

		result = min(result, dist[i][i]);
	}

	if (result >= INT32_MAX)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << result << '\n';
	}

	return 0;
}