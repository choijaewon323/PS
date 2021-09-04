#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, index, child;
	vector<vector<int>> nodes(20);
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

	for(int i = 0; i < m; i++)
	{
		cin >> index;

		if(nodes[index - 1].empty())
		{
			cout << 0 << '\n';
		}
		else
		{
			for(auto element : nodes[index - 1])
			{
				cout << element << " ";
			}
			cout << '\n';
		}
	}

	return 0;
}