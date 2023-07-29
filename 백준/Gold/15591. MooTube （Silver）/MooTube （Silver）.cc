#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> edges[5001];

#define INF	1000000001

vector<bool> visited;

int bfs(int start, int N, int k)
{
	visited = vector<bool>(N + 1, false);

	visited[start] = true;
	queue<pair<int, int>> q;
	q.push({ start, INF });

	int answer = 0;

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < edges[present.first].size(); i++)
		{
			pair<int, int> next = edges[present.first][i];

			if (!visited[next.first])
			{
				if (min(present.second, next.second) >= k)
				{
					answer++;
				}
				q.push({ next.first, min(present.second, next.second) });
				visited[next.first] = true;
			}
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, Q;

	cin >> N >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int p, q, r;

		cin >> p >> q >> r;

		edges[p].push_back({ q, r });
		edges[q].push_back({ p, r });
	}

	for (int i = 0; i < Q; i++)
	{
		int k, v;

		cin >> k >> v;

		int cnt = bfs(v, N, k);
		
		cout << cnt << '\n';
	}

	return 0;
}