#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int r, c, k;
int rowSize = 3, columnSize = 3;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

vector<int> rowSort(vector<int> &temp)
{
	vector<int> cnt(101, 0);
	vector<int> result;

	for (auto i : temp)
	{
		cnt[i]++;
	}

	vector<pair<int, int>> res;

	for (int i = 1; i <= 100; i++)
	{
		if (cnt[i] != 0)
		{
			res.push_back(make_pair(i, cnt[i]));
		}
	}

	sort(res.begin(), res.end(), compare);

	for (auto i : res)
	{
		result.push_back(i.first);
		result.push_back(i.second);
	}

	return result;
}

void operR(vector<vector<int>> &arr)
{
	int maxSize = -1;

	for (int row = 0; row < rowSize; row++)
	{
		vector<int> temp;

		for (int col = 0; col < columnSize; col++)
		{
			if (arr[row][col] != 0)
			{
				temp.push_back(arr[row][col]);
			}
			arr[row][col] = 0;
		}

		temp = rowSort(temp);



		for (int i = 0; i < temp.size(); i++)
		{
			if (i == 100)
			{
				break;
			}
			arr[row][i] = temp[i];
		}
		maxSize = max(maxSize, (int)temp.size());
	}

	columnSize = max(columnSize, maxSize);

	if (columnSize > 100)
	{
		columnSize = 100;
	}
}

void operC(vector<vector<int>> &arr)
{
	int maxSize = -1;

	for (int col = 0; col < columnSize; col++)
	{
		vector<int> temp;

		for (int row = 0; row < rowSize; row++)
		{
			if (arr[row][col] != 0)
			{
				temp.push_back(arr[row][col]);
			}
			arr[row][col] = 0;
		}

		temp = rowSort(temp);

		for (int i = 0; i < temp.size(); i++)
		{
			if (i == 100)
			{
				break;
			}
			arr[i][col] = temp[i];
		}

		maxSize = max(maxSize, (int)temp.size());
	}

	rowSize = max(rowSize, maxSize);

	if (rowSize > 100)
	{
		rowSize = 100;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> arr;

	cin >> r >> c >> k;

	arr = vector<vector<int>>(100, vector<int>(100, 0));

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> arr[y][x];
		}
	}

	if (arr[r - 1][c - 1] == k)
	{
		cout << 0 << '\n';
		return 0;
	}

	for (int sec = 1; sec <= 100; sec++)
	{
		if (rowSize >= columnSize)
		{
			operR(arr);
		}
		else
		{
			operC(arr);
		}

		if (arr[r - 1][c - 1] == k)
		{
			cout << sec << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
	return 0;
}