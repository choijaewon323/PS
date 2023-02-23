#include <iostream>
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<pair<int, int>>> edges;

int prim(int v, int start)
{
	priority_queue<pair<int, int>> pq;
	visited = vector<bool>(v + 1, false);

	for (int i = 0; i < edges[start].size(); i++)
	{
		int next = edges[start][i].first;
		int cost = edges[start][i].second;

		pq.push(make_pair(-cost, next));
	}

	visited[start] = true;

	int result = 0;
	while (!pq.empty())
	{
		int present = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (!visited[present])
		{
			visited[present] = true;
			result += cost;

			for (int i = 0; i < edges[present].size(); i++)
			{
				int next = edges[present][i].first;
				int nextDist = edges[present][i].second;
				
				if (!visited[next])
				{
					pq.push(make_pair(-nextDist, next));
				}
			}
		}
	}

	return result;
}

void input()
{
	int v, e;

	cin >> v >> e;

	edges = vector<vector<pair<int, int>>>(v + 1);

	for (int i = 1; i <= e; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}

	int result = prim(v, 1);

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();

	return 0;
}