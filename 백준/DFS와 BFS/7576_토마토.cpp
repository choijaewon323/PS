#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int box[1001][1001];
int actualNumOfTomato;
int days[1001][1001];
vector<pair<int, int>> realTomatoes;

int bfs()
{
	queue<pair<int, int>> q;
	int num = realTomatoes.size();
	for (auto i : realTomatoes)
	{
		q.push(make_pair(i.first, i.second));
		days[i.first][i.second] = 1;
	}

	while (true)
	{
		pair<int,int> present = q.front();
		int y, x;
		
		y = present.first + 1;
		x = present.second;
		if (days[y][x] == 0)
		{
			if (box[y][x] == 1)
			{
				q.push(make_pair(y, x));
				days[y][x] = days[present.first][present.second] + 1;
				num++;
				box[y][x] = 2;
			}
		}
		y = present.first;
		x = present.second + 1;
		if (days[y][x] == 0)
		{
			if (box[y][x] == 1)
			{
				q.push(make_pair(y, x));
				days[y][x] = days[present.first][present.second] + 1;
				box[y][x] = 2;
				num++;
			}
		}
		y = present.first - 1;
		x = present.second;
		if (days[y][x] == 0)
		{
			if (box[y][x] == 1)
			{
				q.push(make_pair(y, x));
				days[y][x] = days[present.first][present.second] + 1;
				num++;
				box[y][x] = 2;
			}
		}
		y = present.first;
		x = present.second - 1;
		if (days[y][x] == 0)
		{
			if (box[y][x] == 1)
			{
				q.push(make_pair(y, x));
				days[y][x] = days[present.first][present.second] + 1;
				num++;
				box[y][x] = 2;
			}
		}
		
		q.pop();
		if (q.empty())
		{
			break;
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (days[i][j] > result)
			{
				result = days[i][j];
			}
		}
	}
	return result - 1;
}

int main()
{
	vector<int> results;
	int unripe = 0;
	int ripe = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			box[i][j] = temp + 1;
			if (box[i][j] == 2 || box[i][j] == 1)
			{
				actualNumOfTomato++;
				if (box[i][j] == 2)
				{
					realTomatoes.push_back(make_pair(i, j));
					ripe++;
				}
				if (box[i][j] == 1)
				{
					unripe++;
				}
			}
		}
	}
	if (unripe == 0)
	{
		cout << 0 << '\n';
	}
	else if (ripe == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		bool flag = true;
		int result = bfs();
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (box[i][j] == 1)
				{
					flag = false;
				}
			}
		}

		if (flag)
		{
			cout << result << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
	return 0;
}