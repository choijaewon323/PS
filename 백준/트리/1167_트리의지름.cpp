#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;
vector<list<pair<int, int>>> edges(100001);
bool isChecked[100001];
int resultLength;
int resultNode;
void dfs(int node, int length)
{
	isChecked[node] = true;
	for (auto i : edges[node])
	{
		if (!isChecked[i.first])
		{
			dfs(i.first, length + i.second);
		}
	}
	if (length > resultLength)
	{
		resultLength = length;
		resultNode = node;
	}
}
int main()
{
	int v;
	cin >> v;
	for (int i = 0; i < v; i++)
	{
		int node, n1, n2;
		cin >> node;
		while (true)
		{
			cin >> n1;
			if (n1 == -1)
			{
				break;
			}
			cin >> n2;
			edges[node].push_back(make_pair(n1, n2));
		}
	}
	dfs(1, 0);
	int tempNode = resultNode;
	int tempLength = resultLength;
	resultNode = 0;
	resultLength = 0;
	for (int i = 0; i <= 100000; i++)
	{
		isChecked[i] = false;
	}
	dfs(tempNode, 0);
	cout << resultLength << '\n';
	return 0;
}