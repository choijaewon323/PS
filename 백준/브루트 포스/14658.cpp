#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> stars;

int n, m, l, k;

bool inRange(int startY, int endY, int startX, int endX, int y, int x)
{
	if (startY <= y && y <= endY && startX <= x && x <= endX)
	{
		return true;
	}
	return false;
}

int func(int startY, int startX)
{
	int endY = startY + l;
	int endX = startX + l;
	int result = 0;

	for (int i = 0; i < stars.size(); i++)
	{
		int x = stars[i].first;
		int y = stars[i].second;

		if (!inRange(startY, endY, startX, endX, y, x))
		{
			result++;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> l >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;

		cin >> x >> y;

		stars.push_back(make_pair(x, y));
	}

	int result = k;

	for (int i = 0; i < stars.size(); i++)
	{
		int x = stars[i].first;

		for (int j = 0; j < stars.size(); j++)
		{
			int y = stars[j].second;

			result = min(result, func(y, x));
		}
	}

	cout << result << '\n';

	return 0;
}