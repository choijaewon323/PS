#include <iostream>
#include <vector>
using namespace std;

vector<int> edges;
vector<bool> visited;
vector<bool> done;
int cnt;

void dfs(int start)
{
	visited[start] = true;

	int next = edges[start];

	if (!visited[next])
	{
		dfs(next);
	}
	else if (!done[next])
	{
		for (int i = next; i != start; i = edges[i])
		{
			cnt++;
		}
		cnt++;
	}
	done[start] = true;
}

int main()
{
	int test_case;

	cin >> test_case;

	for (int test = 0; test < test_case; test++)
	{
		int n;

		cin >> n;

		edges = vector<int>(n + 1, -1);
		visited = vector<bool>(n + 1, false);
		done = vector<bool>(n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			int temp;

			cin >> temp;
			edges[i] = temp;
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}

		cout << n - cnt << '\n';
		cnt = 0;
	}

	return 0;
}