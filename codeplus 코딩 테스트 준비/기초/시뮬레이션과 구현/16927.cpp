#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r;

int arr[301][301];

void rotation(int startY, int startX, int endY, int endX, int count)
{
	for (int k = 0; k < count; k++)
	{
		int leftUp = arr[startY][startX];
		int leftDown = arr[endY][startX];
		int rightUp = arr[startY][endX];
		int rightDown = arr[endY][endX];

		// 아래
		for (int y = endY; y >= startY + 1; y--)
		{
			arr[y][startX] = arr[y - 1][startX];
		}

		// 오른쪽
		for (int x = endX; x >= startX + 1; x--)
		{
			if (x == startX + 1)
			{
				arr[endY][x] = leftDown;
				continue;
			}
			arr[endY][x] = arr[endY][x - 1];
		}

		// 위쪽
		for (int y = startY; y <= endY - 1; y++)
		{
			if (y == endY - 1)
			{
				arr[y][endX] = rightDown;
				continue;
			}
			arr[y][endX] = arr[y + 1][endX];
		}

		// 왼쪽
		for (int x = startX; x <= endX - 1; x++)
		{
			if (x == endX - 1)
			{
				arr[startY][x] = rightUp;
				continue;
			}
			arr[startY][x] = arr[startY][x + 1];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int i = 0; i < min(n, m) / 2; i++)
	{
		int startY, startX, endY, endX;
		startY = 1 + i;
		startX = 1 + i;
		endY = n - i;
		endX = m - i;

		int count = (endY - startY) * 2 + (endX - startX) * 2;
		count = r % count;
		rotation(1 + i, 1 + i, n - i, m - i, count);
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}