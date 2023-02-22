#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n, d, c;
vector<vector<pair<int, int>>> edges;
vector<int> dist;

vector<int> dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	dist = vector<int>(n + 1, INF);
	vector<int> result;

	dist[start] = 0;
	pq.push(make_pair(0, start));

	int last = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int present = pq.top().second;
		pq.pop();

		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i].first;
			int nextDist = cost + edges[present][i].second;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] < INF)
		{
			cnt++;
			last = max(last, dist[i]);
		}
	}
	result.push_back(cnt);
	result.push_back(last);

	return result;
}

void input()
{
	int test;

	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> n >> d >> c;

		edges = vector<vector<pair<int, int>>>(n + 1);

		for (int i = 0; i < d; i++)
		{
			int a, b, s;

			cin >> a >> b >> s;
			edges[b].push_back(make_pair(a, s));
		}

		vector<int> result = dijkstra(c);

		for (auto r : result)
		{
			cout << r << " ";
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

	return 0;
}