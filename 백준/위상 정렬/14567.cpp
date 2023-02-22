#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;
vector<int> edges[1001];
int visited[1001];

void dfs(int start, int semester)
{
	visited[start] = semester;

	for (int i = 0; i < edges[start].size(); i++)
	{
		int next = edges[start][i];

		if (visited[next] == 0 || visited[next] <= semester)
		{
			dfs(next, semester + 1);
		}
	}
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

void init()
{
	for (int i = 0; i < 1001; i++)
	{
		visited[i] = false;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i, 1);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << visited[i] << " ";
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