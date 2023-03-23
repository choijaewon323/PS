#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

int n;
bool adjacentMatrix[MAX + 1][MAX + 1];
vector<bool> visited;

void dfs(int node, int prev)
{
	if (prev != -1)
	{
		visited[node] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (adjacentMatrix[node][i] && !visited[i])
		{
			dfs(i, node);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<bool>> answer;
	cin >> n;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> adjacentMatrix[y][x];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		visited = vector<bool>(n + 1, false);
		dfs(i, -1);

		answer.push_back(visited);
	}

	for (int y = 0; y < answer.size(); y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cout << answer[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}