#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edges[101];
int n;
vector<pair<int, int>> answer;
vector<int> visited;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int bfs(int start, int end)
{
	visited = vector<int>(101, 0);
	queue<int> q;

	visited[start] = 1;
	q.push(start);

	while (!q.empty())
	{
		int present = q.front();
		q.pop();

		if (present == end)
		{
			return visited[present] - 1;
		}

		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i];

			if (!visited[next])
			{
				q.push(next);
				visited[next] = visited[present] + 1;
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;

		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}

			temp += bfs(i, j);
		}

		answer.push_back(make_pair(i, temp));
	}

	sort(answer.begin(), answer.end(), compare);

	cout << answer.front().first << '\n';

	return 0;
}