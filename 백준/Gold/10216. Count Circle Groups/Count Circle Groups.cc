#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double distance(int ay, int ax, int by, int bx)
{
	double distY = (ay - by);
	double distX = (ax - bx);
	double temp = distY * distY + distX * distX;
	return sqrt(temp);
}

typedef struct _node
{
	int num;
	int y;
	int x;
	int r;
} node;

vector<node> enemies;

int parent[3000];

void init(int N)
{
	for (int i = 0; i < N; i++)
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;

	for (int test = 0; test < T; test++)
	{
		int N;

		cin >> N;

		init(N);
		enemies.clear();
		for (int i = 0; i < N; i++)
		{
			int x, y, r;

			cin >> x >> y >> r;

			node temp = { i, y, x, r };
			enemies.push_back(temp);
		}

		for (int p = 0; p < enemies.size(); p++)
		{
			node present = enemies[p];

			for (int n = p + 1; n < enemies.size(); n++)
			{
				node next = enemies[n];

				if (distance(present.y, present.x, next.y, next.x) <= present.r + next.r)
				{
					union_find(present.num, next.num);
				}
			}
		}

		vector<bool> occupied(N, false);

		int answer = 0;
		for (int i = 0; i < N; i++)
		{
			int temp = find(i);

			if (!occupied[temp])
			{
				answer++;
				occupied[temp] = true;
			}
		}

		cout << answer << '\n';
	}
}