#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[101];

#define INF 1000000

void init(int N)
{
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
}

int find(int x)
{
	if (parent[x] != x)
	{
		return parent[x] = find(parent[x]);
	}
	return x;
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

vector<int> group[101];

int dist[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N;

	for (int y = 1; y <= 100; y++)
	{
		for (int x = 1; x <= 100; x++)
		{
			if (y == x)
			{
				dist[y][x] = 0;
				continue;
			}
			dist[y][x] = INF;
		}
	}
	
	init(N);
	
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;

		union_find(a, b);
	}

	// floyd-warshall
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int root = find(i);

		group[root].push_back(i);
	}

	int K = 0;
	vector<int> answers;

	// 대표 정하기
	for (int g = 1; g <= 100; g++)
	{
		if (!group[g].empty())
		{
			K++;
			int leader = -1;
			int cnt = INF;

			for (int tempLeader : group[g])
			{
				int tempCnt = 0;
				for (int last : group[g])
				{
					if (tempLeader == last)
					{
						continue;
					}

					if (dist[last][tempLeader] >= INF)
					{
						continue;
					}
					tempCnt = max(dist[last][tempLeader], tempCnt);
				}

				if (cnt > tempCnt)
				{
					cnt = tempCnt;
					leader = tempLeader;
				}
			}

			answers.push_back(leader);
		}
	}

	sort(answers.begin(), answers.end());

	cout << K << '\n';

	for (int tem : answers)
	{
		cout << tem << '\n';
	}

	return 0;
}