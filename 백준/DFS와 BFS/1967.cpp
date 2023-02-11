#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> edges[10001];

int result;
bool visited[10001];

void init()
{
	for (int i = 0; i < 10001; i++)
	{
		visited[i] = false;
	}
}

void dfs(int start, int present, int sum)
{
	visited[present] = true;
	result = max(sum, result);

	for (int i = 0; i < edges[present].size(); i++)
	{
		int next = edges[present][i].first;
		int cost = edges[present][i].second;

		if (!visited[next])
		{
			dfs(start, next, sum + cost);
		}
	}
}

int main()
{
	int n;
	
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i <= n; i++)
	{
		init();
		dfs(i, i, 0);
	}

	cout << result << '\n';

	return 0;
}