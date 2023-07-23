#include <iostream>
#include <vector>
#include <utility>

using namespace std;

char matrix[1000][1000];

int inverter[1000][1000];

int parent[1000000];

void init(int N, int M)
{
	int cnt = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			inverter[y][x] = cnt++;
		}
	}

	for (int i = 0; i < N * M; i++)
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

vector<pair<int, int>> edges;
bool occupied[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	init(N, M);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> matrix[y][x];

			pair<int, int> temp;
			switch (matrix[y][x])
			{
			case 'U':
				temp = { inverter[y][x], inverter[y-1][x] };
				break;

			case 'D':
				temp = { inverter[y][x], inverter[y + 1][x] };
				break;

			case 'L':
				temp = { inverter[y][x], inverter[y][x-1] };
				break;

			case 'R':
				temp = { inverter[y][x], inverter[y][x+1] };
				break;
			}
			edges.push_back(temp);
		}
	}

	for (auto &ed : edges)
	{
		int a = ed.first;
		int b = ed.second;

		union_find(a, b);
	}

	int answer = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int temp = inverter[y][x];

			temp = find(temp);

			if (!occupied[temp])
			{
				answer++;
				occupied[temp] = true;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}