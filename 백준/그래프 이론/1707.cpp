#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define RED 1
#define BLUE 2

list<int> edges[20001];
int colors[20001];
bool visited[20001];

void dfs(int start)
{
	visited[start] = true;
	int startColor = colors[start];
	
	for (auto edge : edges[start])
	{
		if (!visited[edge])
		{
			if (startColor == RED)
			{
				colors[edge] = BLUE;
				dfs(edge);
			}
			else
			{
				colors[edge] = RED;
				dfs(edge);
			}
		}
	}
}

void init()
{
	for (int i = 0; i < 20001; i++)
	{
		edges[i].clear();
		colors[i] = 0;
		visited[i] = false;
	}
}

int main()
{
	int k;
	int v, e;
	int start, end;
	bool result;

	cin >> k;

	for (int test_case = 0; test_case < k; test_case++)
	{
		cin >> v >> e;

		init();

		for (int i = 1; i <= e; i++)
		{
			cin >> start >> end;
			edges[start].push_back(end);
			edges[end].push_back(start);
		}

		for (int i = 1; i < v; i++)
		{
			if (!visited[i])
			{
				colors[i] = RED;
				dfs(i);
			}
		}

		result = true;
		for (int i = 1; i <= v; i++)
		{
			for (auto edge : edges[i])
			{
				if (colors[i] == colors[edge])
				{
					result = false;
					break;
				}
			}
			if (!result)
			{
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
	}

	return 0;
}