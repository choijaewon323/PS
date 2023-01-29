#include <iostream>
#include <algorithm>
using namespace std;

int matrix[12][12];
int n, m;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int isUsed[12][12];
int maxNum = -40001;

void func(int y, int x, int k, int sum)
{
	if (k == 1)
	{
		sum += matrix[y][x];
		if (sum > maxNum)
		{
			maxNum = sum;
		}

		return;
	}

	isUsed[y][x]++;
	for (int i = 0; i < 4; i++)
	{
		int tempY = y + dy[i];
		int tempX = x + dx[i];

		if (tempY >= 0 && tempY < n && tempX >= 0 && tempX < m)
		{
			isUsed[tempY][tempX]++;
		}
	}

	for (int tempY = 0; tempY < n; tempY++)
	{
		for (int tempX = 0; tempX < m; tempX++)
		{
			if (isUsed[tempY][tempX] == 0)
			{
				func(tempY, tempX, k - 1, sum + matrix[y][x]);
			}
		}
	}

	isUsed[y][x]--;
	for (int i = 0; i < 4; i++)
	{
		int tempY = y + dy[i];
		int tempX = x + dx[i];

		if (tempY >= 0 && tempY < n && tempX >= 0 && tempX < m)
		{
			isUsed[tempY][tempX]--;
		}
	}
}

int main()
{
	int k;
	cin >> n >> m >> k;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> matrix[y][x];
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			func(y, x, k, 0);
		}
	}

	cout << maxNum << '\n';

	return 0;
}