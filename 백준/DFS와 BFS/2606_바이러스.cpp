#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector<list<int>> edges(101);
bool isChecked[101];
int result;
void dfs(int node)
{
	result++;
	isChecked[node] = true;
	for (auto n : edges[node])
	{
		if (isChecked[n])
		{
			continue;
		}
		dfs(n);
	}
}
int main()
{
	int numOfComputer, numOfPair;
	cin >> numOfComputer >> numOfPair;
	for (int i = 0; i < numOfPair; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		edges[n1].push_back(n2);
		edges[n2].push_back(n1);
	}
	dfs(1);
	cout << result - 1 << '\n';
	return 0;
}