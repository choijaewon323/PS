#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];

int find(int x)
{
	if (x != parent[x])
	{
		return parent[x] = find(parent[x]);
	}
	return x;
}

bool union_find(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot)
	{
		return true;
	}

	if (aRoot < bRoot)
	{
		parent[bRoot] = aRoot;
	}
	else
	{
		parent[aRoot] = bRoot;
	}

	return false;
}

vector<pair<int, int>> edges;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, k;

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++)
	{
		int c;

		cin >> c;
		edges.push_back({ i, c });
		parent[i] = i;
	}

	sort(edges.begin(), edges.end(), compare);

	for (int i = 0; i < M; i++)
	{
		int v, w;

		cin >> v >> w;

		union_find(v, w);
	}

	int cost = 0;
	for (auto &temp : edges)
	{
		if (find(0) == find(temp.first))
		{
			continue;
		}

		if (temp.second + cost > k)
		{
			continue;
		}

		cost += temp.second;

		union_find(0, temp.first);
	}

	bool result = true;
	for (int i = 1; i <= N; i++)
	{
		if (find(i) != 0)
		{
			result = false;
			break;
		}
	}

	if (result)
	{
		cout << cost << '\n';
	}
	else
	{
		cout << "Oh no" << '\n';
	}

	return 0;
}