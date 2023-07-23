#include <iostream>
#include <vector>

using namespace std;

#define INF 10000000

int dist[251][251];

void init(int n)
{
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (y == x)
			{
				continue;
			}
			dist[y][x] = INF;
		}
	}
}

void floydWarshall(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	init(n);

	for (int i = 0; i < m; i++)
	{
		int u, v, b;

		cin >> u >> v >> b;

		if (b == 0)
		{
			dist[u][v] = 0;
			dist[v][u] = 1;
		}
		else
		{
			dist[u][v] = 0;
			dist[v][u] = 0;
		}
	}

	floydWarshall(n);

	int k;

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int s, e;

		cin >> s >> e;

		cout << dist[s][e] << '\n';
	}

	return 0;
}