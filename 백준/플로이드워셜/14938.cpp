#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n, m, r;
int items[101];
int dist[101][101];

void init()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = INF;
		}
	}
}

void floyd_warshall()
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

void input()
{
	init();

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}
}

void solution()
{
	floyd_warshall();

	int result = 0;

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;

		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] != INF && dist[i][j] <= m)
			{
				temp += items[j];
			}
		}

		result = max(result, temp);
	}

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}