#include <iostream>
using namespace std;
int coloredPaper[128][128];
int white;
int blue;
void func(int length, int y, int x)
{
	if (length == 1)
	{
		if (coloredPaper[y][x] == 0)
		{
			white++;
		}
		else
		{
			blue++;
		}
		return;
	}
	bool flag = true;
	for (int i = y; i < y + length; i++)
	{
		for (int j = x; j < x + length; j++)
		{
			if (coloredPaper[y][x] != coloredPaper[i][j])
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	if (flag)
	{
		if (coloredPaper[y][x] == 0)
		{
			white++;
		}
		else
		{
			blue++;
		}
	}
	else
	{
		func(length / 2, y, x);
		func(length / 2, y + length / 2, x);
		func(length / 2, y, x + length / 2);
		func(length / 2, y + length / 2, x + length / 2);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> coloredPaper[i][j];
		}
	}
	func(n, 0, 0);
	cout << white << '\n' << blue << '\n';
	return 0;
}