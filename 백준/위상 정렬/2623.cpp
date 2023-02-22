#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> edges[1001];
bool visited[1001];
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
		int num;

		cin >> num;


		vector<int> temp;

		for (int i = 0; i < num; i++)
		{
			int t;
			cin >> t;
			temp.push_back(t);
		}

		for (int i = 0; i < temp.size() - 1; i++)
		{
			int a = temp[i];
			int b = temp[i + 1];
			edges[a].push_back(b);
		}
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

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (auto e : edges[result[j]])
			{
				if (result[i] == e)
				{
					cout << 0 << '\n';
					return;
				}
			}
		}
	}

	for (auto r : result)
	{
		cout << r << '\n';
	}
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