#include <iostream>
#include <vector>
using namespace std;
vector<int> nodes[20];
void search(vector<int>& node, int index, int depth)
{
	if(node.size() == 0) return;
	if(index == node[0])
	{
		cout << depth << '\n';
	}
	for(int i = 1; i < node.size(); i++)
	{
		search(nodes[node[i] - 1], index, depth + 1);
	}
}
int main()
{
	int n, m, index, child;
	cin >> n >> m;
	for(int i = 1; i <= 20; i++)
	{
		nodes[i - 1].push_back(i);
	}
	for(int i = 0; i < n; i++)
	{
		cin >> index;
		cin >> child;
		while(child != 0)
		{
			nodes[index - 1].push_back(child);
			cin >> child;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cin >> index;
		search(nodes[0], index, 0);
	}
	return 0;
}