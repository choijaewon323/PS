#include <iostream>
using namespace std;

char arr[50][100];

int code[8];

int power(int n, int r)
{
	if (r == 0)
	{
		return 1;
	}
	else
	{
		int result = 1;

		for (int i = 0; i < r; i++)
		{
			result *= n;
		}

		return result;
	}
}

int main()
{
	int testNum;

	cin >> testNum;

	for (int test_case = 1; test_case <= testNum; test_case++)
	{
		int n, m;
		int tempY, tempX;
		cin >> n >> m;	// n 세로 크기, m 가로 크기

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				cin >> arr[y][x];
			}
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = m - 1; x >= 0; x--)
			{
				if (arr[y][x] == '1')
				{
					tempY = y;
					tempX = x - 55;
					break;
				}
			}
		}

		int count = 0;
		for (int x = tempX; x < tempX + 56; x += 7)
		{
			string s = "";
			int result = 0;

			for (int r = 0; r < 7; r++)
			{
				result += (arr[tempY][x + r] - '0') * power(2, 6 - r);
			}

			switch (result)
			{
			case 13:
				code[count] = 0;
				break;
			case 25:
				code[count] = 1;
				break;
			case 19:
				code[count] = 2;
				break;
			case 61:
				code[count] = 3;
				break;
			case 35:
				code[count] = 4;
				break;
			case 49:
				code[count] = 5;
				break;
			case 47:
				code[count] = 6;
				break;
			case 59:
				code[count] = 7;
				break;
			case 55:
				code[count] = 8;
				break;
			case 11:
				code[count] = 9;
				break;
			}
			count++;
		}

		int even = 0;
		int odd = 0;
		for (int i = 0; i < 8; i++)
		{
			int temp = code[i];
			if (i % 2 == 0)
			{
				even += temp;
			}
			else
			{
				odd += temp;
			}
		}

		int answer = even + odd;

		if ((even * 3 + odd) % 10 == 0)
		{
			cout << "#" << test_case << " " << answer << '\n';
		}
		else
		{
			cout << "#" << test_case << " " << 0 << '\n';
		}
	}

	return 0;
}