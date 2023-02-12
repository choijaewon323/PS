#include <iostream>
using namespace std;

int plan[1000];
int parent[201];

bool isConnected[201][201];

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return find(parent[x]);
	}
}

void union_find(int y, int x)
{
	int rootY, rootX;
	
	rootY = find(y);
	rootX = find(x);
	parent[rootY] = rootX;
}

int main()
{
	int n;
	int m;
	bool result = true;

	cin >> n;
	cin >> m;
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			int temp;
			
			cin >> temp;

			if (temp == 1)
			{
				isConnected[y][x] = true;
				isConnected[x][y] = true;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> plan[i];
	}

	for (int i = 1; i <= 200; i++)
	{
		parent[i] = i;
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (isConnected[y][x])
			{
				union_find(y, x);
			}
		}
	}

	int temp = find(plan[0]);
	for (int i = 1; i < m; i++)
	{
		if (find(plan[i]) != temp)
		{
			result = false;
			break;
		}
	}

	if (result)
	{
		cout << "YES" << '\n';
	}
	else
	{
		cout << "NO" << '\n';
	}

	return 0;
}