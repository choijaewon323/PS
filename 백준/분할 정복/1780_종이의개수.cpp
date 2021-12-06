#include <iostream>
using namespace std;

int paper[2188][2188];
int result[3];

void func(int n, int firstY, int lastY, int firstX, int lastX)
{
	int temp = paper[firstY][firstX];
	bool flag = true;

	if (n == 1)
	{
		result[(++temp)]++;
		return;
	}

	for (int i = firstY; i <= lastY; i++)
	{
		for (int j = firstX; j <= lastX; j++)
		{
			if (paper[i][j] != temp)
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
		result[(++temp)]++;
	}
	else
	{
		for (int i = firstY; i <= lastY; i += (n / 3))
		{
			for (int j = firstX; j <= lastX; j += (n / 3))
			{
				func(n / 3, i, i + (n / 3) - 1, j, j + (n / 3) - 1);
			}
		}
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
			cin >> paper[i][j];
		}
	}

	func(n, 0, n - 1, 0, n - 1);

	for (int i = 0; i < 3; i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}