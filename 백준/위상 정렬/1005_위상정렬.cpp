#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> edges;
vector<int> times;
vector<int> incoming;
vector<int> presentIncoming;
vector<int> dist;
vector<bool> visited;

void dfs(int start)
{
	visited[start] = true;

	if (dist[start] == -1)
	{
		dist[start] = times[start];
	}
	else
	{
		dist[start] += times[start];
	}

	for (int i = 0; i < edges[start].size(); i++)
	{
		int next = edges[start][i];

		if (!visited[next])
		{
			presentIncoming[next]++;
			dist[next] = max(dist[next], dist[start]);

			if (presentIncoming[next] == incoming[next])
			{
				dfs(next);
			}
		}
	}
}

void input()
{
	int t;

	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int n, k, w;

		cin >> n >> k;

		times = vector<int>(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> times[i];
		}

		incoming = vector<int>(n + 1, 0);
		edges = vector<vector<int>>(n + 1);
		for (int i = 0; i < k; i++)
		{
			int x, y;

			cin >> x >> y;
			edges[x].push_back(y);
			incoming[y]++;
		}

		cin >> w;

		presentIncoming = vector<int>(n + 1, 0);
		visited = vector<bool>(n + 1, false);
		dist = vector<int>(n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i] && incoming[i] == 0)
			{
				dfs(i);
			}
		}

		cout << dist[w] << '\n';
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