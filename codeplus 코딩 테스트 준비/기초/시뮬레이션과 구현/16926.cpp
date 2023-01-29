#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> func(vector<vector<int>>& arr)
{
	vector<vector<int>> newArr(301, vector<int>(301));
	int minimum = min(n, m);
	int startY, startX, endY, endX;
	
	for (int i = 1; i <= minimum / 2; i++)
	{
		startY = i;
		startX = i;
		endY = n - i + 1;
		endX = m - i + 1;

		// 1. down
		for (int y = startY; y <= endY - 1; y++)
		{
			newArr[y + 1][startX] = arr[y][startX];
		}

		// 2. right
		for (int x = startX; x <= endX - 1; x++)
		{
			newArr[endY][x + 1] = arr[endY][x];
		}

		// 3. up
		for (int y = endY; y >= startY + 1; y--)
		{
			newArr[y - 1][endX] = arr[y][endX];
		}

		// 4. left
		for (int x = endX; x >= startX + 1; x--)
		{
			newArr[startY][x - 1] = arr[startY][x];
		}
	}

	return newArr;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> input(301, vector<int>(301));
	vector<vector<int>> ret(301, vector<int>(301));
	int r;

	cin >> n >> m >> r;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cin >> input[y][x];
		}
	}

	ret = func(input);
	for (int i = 1; i < r; i++)
	{
		vector<vector<int>> temp(301, vector<int>(301));
		temp = func(ret);
		ret = temp;
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			cout << ret[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}