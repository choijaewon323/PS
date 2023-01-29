#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ability[21][21];
int n;
bool isUsed[21];

int func(vector<int> &start, int count)
{
	if (count == start.size())
	{
		vector<int> link;
		int startSize = start.size();
		int linkSize;
		int startAb = 0;
		int linkAb = 0;

		for (int i = 1; i <= n; i++)
		{
			if (!isUsed[i])
			{
				link.push_back(i);
			}
		}

		linkSize = link.size();

		for (int y = 0; y < startSize; y++)
		{
			for (int x = 0; x < startSize; x++)
			{
				startAb += ability[start[y]][start[x]];
			}
		}

		for (int y = 0; y < linkSize; y++)
		{
			for (int x = 0; x < linkSize; x++)
			{
				linkAb += ability[link[y]][link[x]];
			}
		}

		return abs(startAb - linkAb);
	}

	if (start.empty())
	{
		int result = INT32_MAX;

		for (int i = 1; i <= n - count + 1; i++)
		{
			start.push_back(i);
			isUsed[i] = true;
			result = min(result, func(start, count));
			isUsed[i] = false;
			start.pop_back();
		}

		return result;
	}
	
	int result = INT32_MAX;

	for (int i = start.back() + 1; i <= n; i++)
	{
		if (!isUsed[i])
		{
			start.push_back(i);
			isUsed[i] = true;
			result = min(result, func(start, count));
			isUsed[i] = false;
			start.pop_back();
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> start;
	int result = INT32_MAX;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ability[i][j];
		}
	}

	for (int i = 1; i <= n / 2; i++)
	{
		result = min(result, func(start, i));
	}

	cout << result << '\n';

	return 0;
}