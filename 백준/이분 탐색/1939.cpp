#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int startPlant, endPlant;
vector<pair<int, int>> edges[10001];
bool visited[10001];
int small = 1000000001;
int big;
int result;

void init()
{
	for (int i = 0; i < 10001; i++)
	{
		visited[i] = false;
	}
}

void dfs(int start, int weight)
{
	visited[start] = true;

	for (int i = 0; i < edges[start].size(); i++)
	{
		int next = edges[start][i].first;
		int nextWeight = edges[start][i].second;

		if (!visited[next] && nextWeight >= weight)
		{
			dfs(next, weight);
		}
	}
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));

		small = min(small, c);
		big = max(big, c);
	}

	cin >> startPlant >> endPlant;
}

void solution()
{
	while (small <= big)
	{
		int mid = (small + big) / 2;

		init();
		dfs(startPlant, mid);

		if (visited[endPlant])
		{
			result = mid;
			small = mid + 1;
		}
		else
		{
			big = mid - 1;
		}
	}

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}