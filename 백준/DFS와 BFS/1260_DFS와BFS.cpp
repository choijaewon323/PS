#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
vector<list<int>> edges(1001);
bool isChecked[1001];
void dfs(int node)
{
	cout << node << " ";
	isChecked[node] = true;
	for (auto next : edges[node])
	{
		if (isChecked[next])
		{
			continue;
		}
		dfs(next);
	}
}
void bfs(int firstNode)
{
	cout << firstNode << " ";
	queue<int> q;
	isChecked[firstNode] = true;
	q.push(firstNode);
	while (true)
	{
		int temp = q.front();
		for (auto n : edges[temp])
		{
			if (isChecked[n])
			{
				continue;
			}
			cout << n << " ";
			isChecked[n] = true;
			q.push(n);
		}
		q.pop();
		if (q.size() == 0)
		{
			break;
		}
	}
}
int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		edges[n1].push_back(n2);
		edges[n2].push_back(n1);
	}
	for (int i = 1; i <= 1000; i++)
	{
		edges[i].sort();
	}
	dfs(v);
	cout << '\n';
	for (int i = 0; i <= 1000; i++)
	{
		isChecked[i] = false;
	}
	bfs(v);
	cout << '\n';
	return 0;
}