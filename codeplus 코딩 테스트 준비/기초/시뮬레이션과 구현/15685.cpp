#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

int matrix[101][101];
string dragon[4][11];

string convert(string input)
{
	string result = "";

	for (auto i : input)
	{
		if (i == 'R')
		{
			result += 'L';
		}
		else if (i == 'D')
		{
			result += 'U';
		}
		else if (i == 'L')
		{
			result += 'R';
		}
		else if (i == 'U')
		{
			result += 'D';
		}
	}

	return result;
}

string rotation(string input)
{
	string result = "";

	for (auto i : input)
	{
		if (i == 'L')
		{
			result += 'U';
		}
		else if (i == 'U')
		{
			result += 'R';
		}
		else if (i == 'R')
		{
			result += 'D';
		}
		else if (i == 'D')
		{
			result += 'L';
		}
	}

	return result;
}


void init()
{
	dragon[RIGHT][0] = "R";
	dragon[UP][0] = "U";
	dragon[LEFT][0] = "L";
	dragon[DOWN][0] = "D";

	for (int direct = 0; direct < 4; direct++)
	{
		for (int gen = 1; gen < 11; gen++)
		{		
			string prev = dragon[direct][gen - 1];
			string converted = convert(prev);
			string rotated = rotation(converted);
			reverse(rotated.begin(), rotated.end());
			prev += rotated;
			dragon[direct][gen] = prev;
		}
	}
}

bool inRange(int y, int x)
{
	if (y >= 0 && y <= 100 && x >= 0 && x <= 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int result = 0;

	init();
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x, y, d, g;
		int tempY, tempX;

		cin >> x >> y >> d >> g;

		tempY = y;
		tempX = x;

		matrix[tempY][tempX]++;
		for (auto dr : dragon[d][g])
		{
			if (dr == 'R')
			{
				tempX++;
			}
			else if (dr == 'U')
			{
				tempY--;
			}
			else if (dr == 'L')
			{
				tempX--;
			}
			else if (dr == 'D')
			{
				tempY++;
			}
			
			if (inRange(tempY, tempX))
			{
				matrix[tempY][tempX]++;
			}
			else
			{
				break;
			}
		}
	}

	for (int ty = 0; ty <= 99; ty++)
	{
		for (int tx = 0; tx <= 99; tx++)
		{
			if (matrix[ty][tx] > 0 &&
				matrix[ty + 1][tx] > 0 &&
				matrix[ty][tx + 1] > 0 &&
				matrix[ty + 1][tx + 1] > 0)
			{
				result++;
			}
		}
	}

	cout << result << '\n';
		
	return 0;
}