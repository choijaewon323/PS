#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> times;
vector<vector<int>> edges;
vector<int> incomingCount;

int bfs(int n, vector<int> start, int end)
{
	vector<int> dist(n + 1, -1);
	vector<int> allIncoming(n + 1, 0);
	queue<int> q;

	for (auto s : start)
	{
		dist[s] = times[s];
		q.push(s);
	}

	while (!q.empty())
	{
		int present = q.front();
		q.pop();

		if (allIncoming[present] == incomingCount[present])
		{
			for (int i = 0; i < edges[present].size(); i++)
			{
				int next = edges[present][i];

				dist[next] = max(dist[present] + times[next], dist[next]);
				allIncoming[next]++;
				
				if (allIncoming[next] == incomingCount[next])
				{
					q.push(next);
				}
			}
		}
		else
		{
			q.push(present);
		}
	}

	return dist[end];
}

void input()
{
	int test;

	cin >> test;

	for (int t = 0; t < test; t++)
	{
		int n, k, w;

		cin >> n >> k;

		times = vector<int>(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> times[i];
		}

		edges = vector<vector<int>>(n + 1);
		incomingCount = vector<int>(n + 1, 0);
		for (int i = 0; i < k; i++)
		{
			int x, y;

			cin >> x >> y;
			edges[x].push_back(y);
			incomingCount[y]++;
		}

		vector<int> incoming;
		for (int i = 1; i <= n; i++)
		{
			if (incomingCount[i] == 0)
			{
				incoming.push_back(i);
			}
		}

		cin >> w;

		cout << bfs(n, incoming, w) << '\n';
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