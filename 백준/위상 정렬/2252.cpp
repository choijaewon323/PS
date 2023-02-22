#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> edges[32001];
bool visited[32001];
vector<int> result;

void dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < edges[start].size(); i++)
	{
		int next = edges[start][i];

		if (!visited[next])
		{
			dfs(next);
		}
	}

	result.push_back(start);
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
	reverse(result.begin(), result.end());

	for (auto r : result)
	{
		cout << r << " ";
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	return 0;
}