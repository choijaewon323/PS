#include <iostream>
using namespace std;

#define INF 100000000000

int n, m;
long long dist[201][201];
int result[201][201];

void init()
{
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
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
					result[i][j] = result[i][k];
				}
			}
		}
	}
}

void input()
{
	init();

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		dist[a][b] = c;
		dist[b][a] = c;
		result[a][b] = b;
		result[b][a] = a;
	}
}

void solution()
{
	floyd_warshall();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cout << "-" << " ";
			}
			else
			{
				cout << result[i][j] << " ";
			}
		}
		cout << '\n';
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