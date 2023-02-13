#include <iostream>
#include <algorithm>
using namespace std;

int input[4][4];
int n, m;
bool bitmask[4][4];

int func(int y, int x)
{
	if (y == n - 1 && x == m)
	{
		int result = 0;

		// 가로 다 더하기
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			for (int j = 0; j < m; j++)
			{
				if (bitmask[i][j] == false)
				{
					if (temp == 0)
					{
						temp = input[i][j];
					}
					else
					{
						temp *= 10;
						temp += input[i][j];
					}
				}
				else
				{
					if (temp != 0)
					{
						result += temp;
						temp = 0;
					}
				}
			}
			result += temp;
		}

		// 세로 다 더하기
		for (int j = 0; j < m; j++)
		{
			int temp = 0;
			for (int i = 0; i < n; i++)
			{
				if (bitmask[i][j] == true)
				{
					if (temp == 0)
					{
						temp = input[i][j];
					}
					else
					{
						temp *= 10;
						temp += input[i][j];
					}
				}
				else
				{
					if (temp != 0)
					{
						result += temp;
						temp = 0;
					}
				}
			}
			result += temp;
		}

		return result;
	}
	if (y == n)
	{
		return 0;
	}
	if (x == m)
	{
		return func(y + 1, 0);
	}

	int result1, result2;

	bitmask[y][x] = false;
	result1 = func(y, x + 1);
	bitmask[y][x] = true;
	result2 = func(y, x + 1);

	return max(result1, result2);
}

int main()
{
	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			char temp;

			cin >> temp;
			input[y][x] = temp - '0';
		}
	}

	cout << func(0, 0) << '\n';

	return 0;
}