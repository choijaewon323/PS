#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INF 100000

int n, m;
int dist[501][501];

void init()
{
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
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
	int result = 0;

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] != INF || dist[j][i] != INF)
			{
				temp++;
			}
		}

		if (temp == n)
		{
			result++;
		}
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