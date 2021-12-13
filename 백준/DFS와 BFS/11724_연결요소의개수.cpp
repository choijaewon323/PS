#include <iostream>
using namespace std;
int n, m;
bool isChecked[1001];
bool edges[1001][1001];
void dfs(int node)
{
	isChecked[node] = true;
	for (int i = 1; i <= n; i++)
	{
		if (edges[node][i])
		{
			if (!isChecked[i])
			{
				dfs(i);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		edges[n1][n2] = true;
		edges[n2][n1] = true;
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!isChecked[i])
		{
			dfs(i);
			result++;
		}
	}
	cout << result << '\n';
	return 0;
}