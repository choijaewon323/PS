#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n, m;
int s, d;

vector<vector<pair<int, int>>> edges;
vector<vector<bool>> edgesValid;
vector<vector<int>> previous;
vector<vector<bool>> check;

long long dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	vector<long long> dist(n, INF);

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int present = pq.top().second;
		pq.pop();


		if (cost > dist[present])
		{
			continue;
		}

		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i].first;
			int nextDist = cost + edges[present][i].second;

			if (edgesValid[present][next])
			{
				if (dist[next] == nextDist)
				{
					previous[next].push_back(present);
				}

				if (dist[next] > nextDist)
				{
					previous[next].clear();
					dist[next] = nextDist;
					pq.push(make_pair(-nextDist, next));
				
					previous[next].push_back(present);
				}

			}

		}
	}

	return dist[d];
}

void solution();

void input()
{
	while (1)
	{
		cin >> n >> m;

		edges = vector<vector<pair<int, int>>>(n);
		previous = vector<vector<int>>(n);

		if (n == 0 && m == 0)
		{
			break;
		}

		cin >> s >> d;

		for (int i = 0; i < m; i++)
		{
			int u, v, p;

			cin >> u >> v >> p;

			edges[u].push_back(make_pair(v, p));
		}


		solution();
	}
}

void erase(int source, int dest)
{
	edgesValid[source][dest] = false;
	check[source][dest] = true;

	if (dest == s)
	{
		return;
	}

	for (auto a : previous[source])
	{
		if (!check[a][source])
		{
			erase(a, source);
		}
	}
}

void solution()
{
	// 첫번째 최단 거리 찾기
	edgesValid = vector<vector<bool>>(n, vector<bool>(n, true));
	dijkstra(s);

	check = vector<vector<bool>>(n, vector<bool>(n, false));

	for (auto a : previous[d])
	{
		erase(a, d);
	}

	// 거의 최단 찾기
	long long result = dijkstra(s);

	if (result >= INF)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << result << '\n';
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