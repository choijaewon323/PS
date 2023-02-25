#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define INF 1000000000

vector<vector<int>> dist;

vector<vector<int>> floyd_warshall(int n)
{
	vector<vector<int>> route(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] != INF && dist[k][j] != INF)
				{
					if (dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						route[i][j] = k;
					}
				}
			}
		}
	}

	return route;
}

int findRouteCount(vector<vector<int>> &route, int start, int end)
{
	int result = 0;
	if (route[start][end] != 0)
	{
		result++;
	}
	else
	{
		return result;
	}

	return findRouteCount(route, start, route[start][end]) + result +
		findRouteCount(route, route[start][end], end);
}

void findRoute(vector<vector<int>> &route, int start, int end)
{
	int temp;
	if (route[start][end] != 0)
	{
		temp = route[start][end];
	}
	else
	{
		return;
	}

	findRoute(route, start, route[start][end]);
	cout << temp << " ";
	findRoute(route, route[start][end], end);
}

void input()
{
	int n, m;

	cin >> n >> m;

	dist = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		
		if (dist[a][b] == INF)
		{
			dist[a][b] = c;
		}
		else
		{
			dist[a][b] = min(dist[a][b], c);
		}
	}

	vector<vector<int>> route = floyd_warshall(n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << dist[i][j] << " ";
			}
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cout << 0 << " ";
			}
			else if (dist[i][j] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				int cnt = findRouteCount(route, i, j);
				cout << cnt + 2 << " ";

				cout << i << " ";
				findRoute(route, i, j);
				cout << j << " ";
			}
			cout << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}