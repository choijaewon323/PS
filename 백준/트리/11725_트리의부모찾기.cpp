#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
vector<list<int>> edges(100001);
int nodes[100001];
bool isDiscovered[100001];
void bfs(int start)
{
	isDiscovered[start] = true;
	queue<int> q;
	q.push(start);
	while (true)
	{
		int current = q.front();
		for (auto i : edges[current])
		{
			if (!isDiscovered[i])
			{
				q.push(i);
				isDiscovered[i] = true;
				nodes[i] = current;
			}
		}
		q.pop();
		if (q.empty())
		{
			break;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		edges[n1].push_back(n2);
		edges[n2].push_back(n1);
	}
	bfs(1);
	for (int i = 2; i <= n; i++)
	{
		cout << nodes[i] << '\n';
	}
	return 0;
}