#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 8

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int n, m;
int matrix[MAX + 1][MAX + 1];

vector<vector<int>> cctv1 = {
	{UP},
	{RIGHT},
	{DOWN},
	{LEFT}
};
vector<vector<int>> cctv2 = {
	{LEFT, RIGHT},
	{UP, DOWN}
};
vector<vector<int>> cctv3 = {
	{UP, RIGHT},
	{RIGHT, DOWN},
	{DOWN, LEFT},
	{LEFT, UP}
};
vector<vector<int>> cctv4 = {
	{LEFT, UP, RIGHT},
	{UP, RIGHT, DOWN},
	{RIGHT, DOWN, LEFT},
	{DOWN, LEFT, UP}
};
vector<vector<int>> cctv5 = {
	{UP, RIGHT, DOWN, LEFT}
};

vector<vector<int>> cctv[6] = {
	{},
	cctv1,
	cctv2,
	cctv3,
	cctv4,
	cctv5
};


void fill(int y, int x, int direction)
{
	switch (direction)
	{
	case UP:
		for (int i = y - 1; i >= 1; i--)
		{
			if (matrix[i][x] == 6)
			{
				break;
			}
			if (1 <= matrix[i][x] && matrix[i][x] <= 5)
			{
				continue;
			}
			matrix[i][x]--;
		}
		break;
	case RIGHT:
		for (int i = x + 1; i <= m; i++)
		{
			if (matrix[y][i] == 6)
			{
				break;
			}
			if (1 <= matrix[y][i] && matrix[y][i] <= 5)
			{
				continue;
			}
			matrix[y][i]--;
		}
		break;
	case DOWN:
		for (int i = y + 1; i <= n; i++)
		{
			if (matrix[i][x] == 6)
			{
				break;
			}
			if (1 <= matrix[i][x] && matrix[i][x] <= 5)
			{
				continue;
			}
			matrix[i][x]--;
		}
		break;
	case LEFT:
		for (int i = x - 1; i >= 1; i--)
		{
			if (matrix[y][i] == 6)
			{
				break;
			}
			if (1 <= matrix[y][i] && matrix[y][i] <= 5)
			{
				continue;
			}
			matrix[y][i]--;
		}
		break;
	}
}

void blank(int y, int x, int direction)
{
	switch (direction)
	{
	case UP:
		for (int i = y - 1; i >= 1; i--)
		{
			if (matrix[i][x] == 6)
			{
				break;
			}
			if (1 <= matrix[i][x] && matrix[i][x] <= 5)
			{
				continue;
			}
			matrix[i][x]++;
		}
		break;
	case RIGHT:
		for (int i = x + 1; i <= m; i++)
		{
			if (matrix[y][i] == 6)
			{
				break;
			}
			if (1 <= matrix[y][i] && matrix[y][i] <= 5)
			{
				continue;
			}
			matrix[y][i]++;
		}
		break;
	case DOWN:
		for (int i = y + 1; i <= n; i++)
		{
			if (matrix[i][x] == 6)
			{
				break;
			}
			if (1 <= matrix[i][x] && matrix[i][x] <= 5)
			{
				continue;
			}
			matrix[i][x]++;
		}
		break;
	case LEFT:
		for (int i = x - 1; i >= 1; i--)
		{
			if (matrix[y][i] == 6)
			{
				break;
			}
			if (1 <= matrix[y][i] && matrix[y][i] <= 5)
			{
				continue;
			}
			matrix[y][i]++;
		}
		break;
	}
}

vector<pair<int, int>> cctvs;

int func(int index)
{
	if (index == cctvs.size())
	{
		int result = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (matrix[i][j] == 0)
				{
					result++;
				}
			}
		}
		return result;
	}

	int y = cctvs[index].first;
	int x = cctvs[index].second;
	int result = INT32_MAX;

	int cctvNum = matrix[y][x];

	for (auto c : cctv[cctvNum])
	{
		for (int i = 0; i < c.size(); i++)
		{
			fill(y, x, c[i]);
		}

		result = min(func(index + 1), result);
		
		for (int i = 0; i < c.size(); i++)
		{
			blank(y, x, c[i]);
		}
	}
	
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cin >> matrix[y][x];

			if (1 <= matrix[y][x] && matrix[y][x] <= 5)
			{
				cctvs.push_back(make_pair(y, x));
			}
		}
	}

	if (cctvs.empty())
	{
		int temp = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (matrix[i][j] == 0)
				{
					temp++;
				}
			}
		}

		cout << temp << '\n';
		return 0;
	}

	int result = func(0);

	cout << result << '\n';

	return 0;
}