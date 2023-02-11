#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[501];
int visited[501];

void init()
{
	for (int i = 0; i < 501; i++)
	{
		edges[i].clear();
		visited[i] = false;
	}
}

bool dfs(int start, int last)
{
	visited[start] = true;

	for (int i = 0; i < edges[start].size(); i++)
	{
		int next = edges[start][i];

		if (last == next)
		{
			continue;
		}

		if (visited[next])
		{
			return false;
		}

		if (dfs(next, start) == false)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test = 1;
	int n, m;

	while (1)
	{
		int result = 0;
		cin >> n >> m;

		if (n == 0 && m == 0)
		{
			break;
		}

		init();

		for (int i = 0; i < m; i++)
		{
			int a, b;
			
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				bool isTree;
				isTree = dfs(i, -1);
				if (isTree)
				{
					result++;
				}
			}
		}

		cout << "Case " << test << ": ";
		if (result == 0)
		{
			cout << "No trees." << '\n';
		}
		else if (result == 1)
		{
			cout << "There is one tree." << '\n';
		}
		else
		{
			cout << "A forest of " << result << " trees." << '\n';
		}
		test++;
	}

	return 0;
}