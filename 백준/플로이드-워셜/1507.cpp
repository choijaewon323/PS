#include <iostream>
using namespace std;

int dist[21][21];
int dist2[21][21];
int n;

int floyd_warshall()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == k || j == k)
				{
					continue;
				}
				if (dist[i][j] == dist[i][k] + dist[k][j])
				{
					dist2[i][j] = 0;
				}
				else if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					return -1;
				}
			}
		}
	}

	return 0;
}

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dist[i][j];
			dist2[i][j] = dist[i][j];
		}
	}
}

void solution()
{
	int correct = floyd_warshall();

	int result = 0;

	if (correct == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				result += dist2[i][j];
			}
		}
		cout << result / 2 << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}
}

int main()
{
	input();
	solution();

	return 0;
}