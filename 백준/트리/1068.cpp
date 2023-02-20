#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[50];
int remov;
int root;
vector<int> tree[50];
bool visited[50];
int result;

void dfs(int start)
{
	visited[start] = true;
	bool isTrav;

	isTrav = false;
	for (int i = 0; i < tree[start].size(); i++)
	{
		int next = tree[start][i];

		if (!visited[next])
		{
			isTrav = true;
			dfs(next);
		}
	}

	if (!isTrav)
	{
		result++;
	}
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		if (arr[i] != -1)
		{
			tree[arr[i]].push_back(i);
		}
		else
		{
			root = i;
		}
	}

	cin >> remov;

	visited[remov] = true;
}

void solution()
{
	if (remov == root)
	{
		cout << 0 << '\n';
		return;
	}
	dfs(root);

	cout << result << '\n';
}

int main()
{
	input();
	solution();

	return 0;
}