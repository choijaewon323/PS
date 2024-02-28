#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100
#define INF 1000000000

int n, m;
int edges[MAX + 1][MAX + 1];

void init()
{
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (y == x)
			{
				edges[y][x] = 0;
			}
			else
			{
				edges[y][x] = INF;
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
				if (edges[i][j] >= edges[i][k] + edges[k][j])
				{
					edges[i][j] = edges[i][k] + edges[k][j];
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
	
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a][b] = min(edges[a][b], c);
	}
	floydWarshall();
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (edges[y][x] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << edges[y][x] << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}