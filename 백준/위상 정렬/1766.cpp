#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 32000

vector<int> edges[MAX + 1];
int n, m;
int cnt[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		edges[a].push_back(b);
		cnt[b]++;
	}

	priority_queue<int> pq;
	vector<int> result;

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 0)
		{
			pq.push(-i);
		}
	}

	while (!pq.empty())
	{
		int present = -pq.top();
		pq.pop();

		result.push_back(present);

		for (int i = 0; i < edges[present].size(); i++)
		{
			int next = edges[present][i];
			cnt[next]--;

			if (cnt[next] == 0)
			{
				pq.push(-next);
			}
		}
	}

	for (auto i : result)
	{
		cout << i << " ";
	}
	cout << '\n';

	return 0;
}