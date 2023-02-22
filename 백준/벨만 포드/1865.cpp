#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

int tc;
int n, m, w;
vector<pair<int, int>> edges[501];
int dist[501];

void wholeInit()
{
	for (int i = 0; i < 501; i++)
	{
		edges[i].clear();
	}
}

void init()
{
	for (int i = 0; i < 501; i++)
	{
		dist[i] = INF;
	}
}

bool bellman_ford(int start)
{
	dist[start] = 0;
	bool updated;

	for (int k = 1; k <= n; k++)
	{
		updated = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < edges[i].size(); j++)
			{
				int next = edges[i][j].first;
				int cost = edges[i][j].second;

				if (dist[next] > dist[i] + cost)
				{
					dist[next] = dist[i] + cost;
					updated = true;
				}
			}
		}

		if (!updated)
		{
			break;
		}
	}

	if (updated)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void solution();

void input()
{
	cin >> tc;

	for (int test = 0; test < tc; test++)
	{
		wholeInit();

		cin >> n >> m >> w;

		for (int i = 0; i < m; i++)
		{
			int s, e, t;

			cin >> s >> e >> t;
			edges[s].push_back(make_pair(e, t));
			edges[e].push_back(make_pair(s, t));
		}

		for (int i = 0; i < w; i++)
		{
			int s, e, t;

			cin >> s >> e >> t;
			edges[s].push_back(make_pair(e, -t));
		}

		solution();
	}
}

void solution()
{
	bool answer = false;

	for (int i = 1; i <= n; i++)
	{
		init();
		bool result = bellman_ford(i);

		if (!result)
		{
			answer = true;
			break;
		}
	}

	if (answer)
	{
		cout << "YES" << '\n';
	}
	else
	{
		cout << "NO" << '\n';
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