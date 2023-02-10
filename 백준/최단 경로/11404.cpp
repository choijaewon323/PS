#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 10000000

int edges[101][101];
long long dist[101][101];
int n;

void init()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (i == j)
			{
				continue;
			}
			dist[i][j] = INF;
		}
	}

	for (int y = 0; y < 101; y++)
	{
		for (int x = 0; x < 101; x++)
		{
			if (edges[y][x] != 0)
			{
				dist[y][x] = edges[y][x];
			}
		}
	}
}

void floydWarshall()
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

	int m;

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (edges[a][b] == 0)
		{
			edges[a][b] = c;
		}
		else
		{
			edges[a][b] = min(edges[a][b], c);
		}
	}

	init();
	floydWarshall();

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			int result;

			if (dist[y][x] >= INF)
			{
				result = 0;
			}
			else
			{
				result = dist[y][x];
			}

			cout << result << " ";
		}
		cout << '\n';
	}

	return 0;
}