#include <iostream>
using namespace std;

int parent[1000001];
int n;

void init()
{
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
}

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void _union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y)
	{
		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;

	cin >> n >> m;

	init();

	for (int i = 0; i < m; i++)
	{
		int command;

		cin >> command;
		
		if (command == 0)
		{
			int a, b;

			cin >> a >> b;
			_union(a, b);
		}
		else
		{
			int a, b;
			int resultA, resultB;
			
			cin >> a >> b;
			resultA = find(a);
			resultB = find(b);

			if (resultA == resultB)
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}