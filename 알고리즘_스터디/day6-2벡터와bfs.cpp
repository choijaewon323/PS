#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> nodes[20];
int depth[20];
void bfs()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int index = q.front();
		for(auto child : nodes[index - 1])
		{
			depth[child - 1] = depth[index - 1] + 1;
			q.push(child);
		}
		q.pop();
	}
}
int main()
{
	int n, m, index, child;
	cin >> n >> m;
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
	bfs();
	for(int i = 0; i < m; i++)
	{
		cin >> index;
		cout << depth[index - 1] << '\n';
	}
	return 0;
}