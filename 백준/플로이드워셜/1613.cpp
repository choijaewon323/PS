#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000

int n, k;
int dist[401][401];

void init()
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			dist[i][j] = 0;
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
				if (dist[i][k] && dist[k][j])
				{
					dist[i][j] = 1;
				}
			}
		}
	}
}

void solution();

void input()
{
	init();
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;

		cin >> a >> b;
		dist[a][b] = 1;
	}

	solution();

	int s;
	cin >> s;

	for (int i = 0; i < s; i++)
	{
		int a, b;

		cin >> a >> b;
		if (dist[a][b])
		{
			cout << -1 << '\n';
			continue;
		}
		if (dist[b][a])
		{
			cout << 1 << '\n';
			continue;
		}
		cout << 0 << '\n';
	}
}

void solution()
{
	floyd_warshall();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}