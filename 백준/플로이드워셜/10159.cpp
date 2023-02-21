#include <iostream>
using namespace std;

#define INF 1000000000

int n, m;
int dist[101][101];

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

void init()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}
}

void input()
{
	cin >> n >> m;

	init();

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		dist[a][b] = 1;
	}
}

void solution()
{
	floyd_warshall();

	for (int i = 1; i <= n; i++)
	{
		int result = 0;

		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF && dist[j][i] == INF)
			{
				result++;
			}
		}

		cout << result << '\n';
	}
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