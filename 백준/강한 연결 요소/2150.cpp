#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<int> edges[10001];
vector<int> transpose[10001];
vector<bool> visited;
stack<int> st;
vector<int> tempNodes;
vector<vector<int>> answer;

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

	st.push(start);
}

void transDfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < transpose[start].size(); i++)
	{
		int next = transpose[start][i];

		if (!visited[next])
		{
			transDfs(next);
		}
	}

	tempNodes.push_back(start);
}

void input()
{
	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b;

		cin >> a >> b;
		edges[a].push_back(b);
		transpose[b].push_back(a);
	}

	visited = vector<bool>(v + 1, false);

	for (int i = 1; i <= v; i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}

	visited = vector<bool>(v + 1, false);

	while (!st.empty())
	{
		int present = st.top();
		st.pop();

		if (!visited[present])
		{
			tempNodes = vector<int>();
			transDfs(present);
			sort(tempNodes.begin(), tempNodes.end());
			tempNodes.push_back(-1);
			answer.push_back(tempNodes);
		}
	}

	cout << answer.size() << '\n';

	sort(answer.begin(), answer.end());

	for (auto a : answer)
	{
		for (auto t : a)
		{
			cout << t << " ";
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