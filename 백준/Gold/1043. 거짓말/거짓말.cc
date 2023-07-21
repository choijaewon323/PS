#include <iostream>
#include <vector>

using namespace std;

int parent[51];

// know : 0

int find(int a)
{
	if (parent[a] == a)
	{
		return a;
	}
	return parent[a] = find(parent[a]);
}

void union_find(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot)
	{
		return;
	}

	if (aRoot < bRoot)
	{
		parent[bRoot] = aRoot;
	}
	else
	{
		parent[aRoot] = bRoot;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	int knowCnt;

	cin >> knowCnt;

	for (int i = 0; i < knowCnt; i++)
	{
		int t;

		cin >> t;
		parent[t] = 0;
	}

	vector<int> party[50];
	for (int i = 0; i < M; i++)
	{
		int come;

		cin >> come;
		if (come > 1)
		{
			int first;

			cin >> first;
			party[i].push_back(first);

			for (int j = 1; j < come; j++)
			{
				int temp;

				cin >> temp;

				union_find(first, temp);
				party[i].push_back(temp);
			}
		}
		else
		{
			int temp;

			cin >> temp;
			party[i].push_back(temp);
		}
	}

	int answer = M;

	for (int i = 0; i < M; i++)
	{
		for (int temp : party[i])
		{
			if (find(temp) == 0)
			{
				answer--;
				break;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}