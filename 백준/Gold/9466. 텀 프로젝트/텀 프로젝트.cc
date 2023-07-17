#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> edges;
vector<vector<int>> transEdges;
vector<bool> visited;
vector<int> tempScc;
vector<vector<int>> scc;
stack<int> st;

void dfs(int start)
{
	int next;

	visited[start] = true;
	next = edges[start];

	if (!visited[next])
	{
		dfs(next);
	}

	st.push(start);
}

void transDfs(int start)
{
	int next;

	visited[start] = true;
	for (int i = 0; i < transEdges[start].size(); i++)
	{
		int next = transEdges[start][i];

		if (!visited[next])
		{
			transDfs(next);
		}
	}

	tempScc.push_back(start);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;

	cin >> test_case;

	for (int test = 0; test < test_case; test++)
	{
		int n, answer;

		cin >> n;

		answer = n;
		visited = vector<bool>(n + 1, false);
		edges = vector<int>(n + 1, -1);
		transEdges = vector<vector<int>>(n + 1, vector<int>());
		st = stack<int>();

		for (int i = 1; i <= n; i++)
		{
			int temp;

			cin >> temp;

			edges[i] = temp;
			transEdges[temp].push_back(i);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}

		visited = vector<bool>(n + 1, false);

		while (!st.empty())
		{
			int present = st.top();
			st.pop();

			if (!visited[present])
			{
				tempScc.clear();
				transDfs(present);
				scc.push_back(tempScc);
			}
		}

		for (int i = 0; i < scc.size(); i++)
		{
			if (scc[i].size() >= 2)
			{
				answer -= scc[i].size();
			}
			else if (scc[i].size() == 1)
			{
				int temp = scc[i].front();

				if (edges[temp] == temp)
				{
					answer--;
				}
			}
		}

		cout << answer << '\n';

		scc.clear();
	}
}