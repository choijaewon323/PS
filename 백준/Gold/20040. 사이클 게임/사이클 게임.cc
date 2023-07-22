#include <iostream>

using namespace std;

int parent[500000];

int find(int x)
{
	if (parent[x] != x)
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
		return false;
	}

	if (aRoot > bRoot)
	{
		parent[bRoot] = aRoot;
	}
	else
	{
		parent[aRoot] = bRoot;
	}

	return true;
}

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	int answer = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v;

		cin >> u >> v;

		if (!union_find(u, v))
		{
			answer = i;
			break;
		}
	}

	if (answer == 0)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << answer << '\n';
	}

	return 0;
}