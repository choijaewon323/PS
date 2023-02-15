#include <iostream>
#include <vector>
using namespace std;

int input[10][10];

vector<vector<int>> cube[11] = {
	{{0,0,0,0,0}, {1,0,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {0,0,0,0,0}},	// 1
	{{0,0,0,0,0}, {0,1,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {0,0,0,0,0}},	// 2
	{{0,0,0,0,0}, {0,0,1,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {0,0,0,0,0}},	// 3
	{{0,0,0,0,0}, {0,0,0,1,0}, {1,1,1,1,0}, {1,0,0,0,0}, {0,0,0,0,0}},	// 4
	{{0,0,0,0,0}, {0,1,0,0,0}, {1,1,1,1,0}, {0,1,0,0,0}, {0,0,0,0,0}},	// 5
	{{0,0,0,0,0}, {0,0,1,0,0}, {1,1,1,1,0}, {0,1,0,0,0}, {0,0,0,0,0}},	// 6
	{{0,0,0,0,0}, {0,0,1,1,1}, {1,1,1,0,0}, {0,0,0,0,0}, {0,0,0,0,0}},	// 7
	{{0,0,0,0,0}, {0,0,1,1,0}, {0,1,1,0,0}, {1,1,0,0,0}, {0,0,0,0,0}},	// 8
	{{0,0,0,0,0}, {0,0,1,1,0}, {1,1,1,0,0}, {1,0,0,0,0}, {0,0,0,0,0}},	// 9
	{{0,0,0,0,0}, {1,1,0,0,0}, {0,1,1,1,0}, {0,1,0,0,0}, {0,0,0,0,0}},	// 10
	{{0,0,0,0,0}, {0,1,0,0,0}, {1,1,1,0,0}, {0,0,1,1,0}, {0,0,0,0,0}}	// 11
};

vector<vector<int>> flip(vector<vector<int>> &input)
{
	vector<vector<int>> result(5, vector<int>(5));

	for (int y = 0; y <= 4; y++)
	{
		for (int x = 0; x <= 4; x++)
		{
			result[y][x] = input[y][4 - x];
		}
	}

	return result;
}

vector<vector<int>> rotate(vector<vector<int>> &input)
{
	vector<vector<int>> result(5, vector<int>(5));

	for (int y = 0; y <= 4; y++)
	{
		for (int x = 0; x <= 4; x++)
		{
			result[y][x] = input[4 - x][y];
		}
	}

	return result;
}

bool match(int startY, int startX, vector<vector<int>> &c)
{
	for (int y = 0; y <= 4; y++)
	{
		for (int x = 0; x <= 4; x++)
		{
			if (input[startY + y][startX + x] != c[y][x])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool isMatched;

	for (int test = 0; test < 3; test++)
	{
		for (int y = 2; y <= 7; y++)
		{
			for (int x = 2; x <= 7; x++)
			{
				cin >> input[y][x];
			}
		}

		isMatched = false;
		for (int y = 0; y <= 5; y++)
		{
			for (int x = 0; x <= 5; x++)
			{
				for (int i = 0; i < 11; i++)
				{
					vector<vector<int>> temp = cube[i];

					if (match(y, x, temp))
					{
						isMatched = true;
						break;
					}

					temp = flip(cube[i]);
					if (match(y, x, temp))
					{
						isMatched = true;
						break;
					}

					temp = cube[i];
					for (int r = 0; r < 3; r++)
					{
						temp = rotate(temp);
						if (match(y, x, temp))
						{
							isMatched = true;
							break;
						}
						temp = flip(temp);
						if (match(y, x, temp))
						{
							isMatched = true;
							break;
						}
						temp = flip(temp);
					}

					if (isMatched)
					{
						break;
					}
				}
				if (isMatched)
				{
					break;
				}
			}

			if (isMatched)
			{
				break;
			}
		}

		if (isMatched)
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}

	return 0;
}