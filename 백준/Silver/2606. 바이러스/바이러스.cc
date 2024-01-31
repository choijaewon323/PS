#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>

using namespace std;

#define MAX 100

int n;
vector<int> edges[MAX + 1];

int bfs(const int start)
{
	vector<bool> visited(n + 1, false);
	queue<int> q;
	
	visited[start] = true;
	q.push(start);
	
	int result = 0;
	while (!q.empty())
	{
		const int present = q.front();
		q.pop();

		for (int i = 0; i < edges[present].size(); i++)
		{
			const int next = edges[present][i];

			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
				result++;
			}
		}
	}

	return result;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;

		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	cout << bfs(1) << '\n';

	return 0;
}