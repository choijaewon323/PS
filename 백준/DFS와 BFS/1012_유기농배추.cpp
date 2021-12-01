#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int locationOfCab[52][52];
bool isDiscovered[52][52];
int numOfWorm;
vector<pair<int, int>> cabbages;
void bfs(int firstY, int firstX)
{
	queue<pair<int, int>> q;
	isDiscovered[firstY][firstX] = true;
	q.push(make_pair(firstY, firstX));
	while (true)
	{
		pair<int, int> node = q.front();
		int y, x;
		y = node.first + 1;
		x = node.second;
		if (!isDiscovered[y][x])
		{
			if (locationOfCab[y][x])
			{
				isDiscovered[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		y = node.first;
		x = node.second + 1;
		if (!isDiscovered[y][x])
		{
			if (locationOfCab[y][x])
			{
				isDiscovered[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		y = node.first - 1;
		x = node.second;
		if (!isDiscovered[y][x])
		{
			if (locationOfCab[y][x])
			{
				isDiscovered[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		y = node.first;
		x = node.second - 1;
		if (!isDiscovered[y][x])
		{
			if (locationOfCab[y][x])
			{
				isDiscovered[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
		q.pop();
		if (q.empty())
		{
			break;
		}
	}
	numOfWorm++;
}
int main()
{
	int t, m, n, k;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			x++;
			y++;
			locationOfCab[y][x] = 1;
			cabbages.push_back(make_pair(y, x));
		}
		for (auto p : cabbages)
		{
			if (!isDiscovered[p.first][p.second])
			{
				bfs(p.first, p.second);
			}
		}
		for (int j = 0; j < 52; j++)
		{
			for (int k = 0; k < 52; k++)
			{
				locationOfCab[j][k] = 0;
				isDiscovered[j][k] = false;
			}
		}
		cabbages.clear();
		cout << numOfWorm << '\n';
		numOfWorm = 0;
	}
	return 0;
}