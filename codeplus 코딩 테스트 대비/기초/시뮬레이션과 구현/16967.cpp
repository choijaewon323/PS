#include <iostream>
using namespace std;

int arr[600][600];
int overlap[600][600];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int h, w, x, y;

	cin >> h >> w >> x >> y;

	for (int height = 0; height < h + x; height++)
	{
		for (int width = 0; width < w + y; width++)
		{
			cin >> arr[height][width];
		}
	}

	// 원래 배열 A 구간
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			overlap[i][j]++;
		}
	}

	// 옮긴 배열 A 구간
	for (int i = x; i < h + x; i++)
	{
		for (int j = y; j < w + y; j++)
		{
			overlap[i][j]++;
		}
	}

	for (int i = 0; i < h + x; i++)
	{
		for (int j = 0; j < w + y; j++)
		{
			if (overlap[i][j] == 2)
			{
				int temp = arr[i][j];
				arr[i][j] = temp - arr[i - x][j - y];
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}