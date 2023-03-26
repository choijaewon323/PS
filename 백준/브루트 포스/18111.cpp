#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define MAX 500

int arr[MAX][MAX];

vector<pair<int, int>> result;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, b;

	cin >> n >> m >> b;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> arr[y][x];
		}
	}

	for (int h = 0; h <= 256; h++)
	{
		int remove = 0, build = 0;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				int height = arr[y][x] - h;

				if (height > 0)
				{
					remove += height;
				}
				else if (height < 0)
				{
					build += (-height);
				}
			}
		}

		if (remove + b >= build)
		{
			int time = build + remove * 2;

			result.push_back(make_pair(time, h));
		}
	}

	sort(result.begin(), result.end(), compare);

	cout << result.front().first << " " << result.front().second << '\n';

	return 0;
}