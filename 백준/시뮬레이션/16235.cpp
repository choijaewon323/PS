#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10

int n, m, k;
int arr[MAX + 1][MAX + 1];
vector<vector<int>> land;
vector<int> trees[MAX + 1][MAX + 1];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool inRange(int y, int x)
{
	if (1 <= y && y <= n && 1 <= x && x <= n)
	{
		return true;
	}
	return false;
}

void springAndSummer()
{
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			vector<int> temp;
			vector<int> death;

			sort(trees[y][x].begin(), trees[y][x].end());
			
			for (auto i : trees[y][x])
			{
				if (land[y][x] >= i)
				{
					land[y][x] -= i;
					i++;
					temp.push_back(i);
				}
				else
				{
					death.push_back(i);
				}
			}
			trees[y][x] = temp;

			for (auto i : death)
			{
				land[y][x] += (i / 2);
			}
		}
	}
}

void fall()
{
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			for (auto i : trees[y][x])
			{
				if (i % 5 == 0)
				{
					for (int i = 0; i < 8; i++)
					{
						int nextY = y + dy[i];
						int nextX = x + dx[i];

						if (inRange(nextY, nextX))
						{
							trees[nextY][nextX].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter()
{
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			land[y][x] += arr[y][x];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	land = vector<vector<int>>(MAX + 1, vector<int>(MAX + 1, 5));

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int y, x, z;

		cin >> y >> x >> z;
		trees[y][x].push_back(z);
	}

	for (int i = 0; i < k; i++)
	{
		springAndSummer();
		fall();
		winter();
	}

	int result = 0;
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			result += trees[y][x].size();
		}
	}

	cout << result << '\n';

	return 0;
}