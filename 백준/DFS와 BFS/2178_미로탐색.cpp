#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int n, m;
int maze[102][102];
int dis[102][102];
vector<int> routes;
void bfs(int firstY, int firstX)
{
	queue<pair<int, int>> q;
	dis[firstY][firstX] = 1;
 	q.push(make_pair(firstY, firstX));
	while (true)
	{
		pair<int,int> node = q.front();
		int y, x;
		y = node.first + 1;
		x = node.second;
		if (dis[y][x] == 0)
		{
			if (maze[y][x])
			{
				if (y == n && x == m)
				{
					routes.push_back(dis[node.first][node.second] + 1);
				}
				else
				{
					q.push(make_pair(y, x));
					dis[y][x] = dis[node.first][node.second] + 1;
				}
			}
		}
		y = node.first;
		x = node.second + 1;
		if (dis[y][x] == 0)
		{
			if (maze[y][x])
			{
				if (y == n && x == m)
				{
					routes.push_back(dis[node.first][node.second] + 1);
				}
				else
				{
					q.push(make_pair(y, x));
					dis[y][x] = dis[node.first][node.second] + 1;
				}
			}
		}
		y = node.first - 1;
		x = node.second;
		if (dis[y][x] == 0)
		{
			if (maze[y][x])
			{
				if (y == n && x == m)
				{
					routes.push_back(dis[node.first][node.second] + 1);
				}
				else
				{
					q.push(make_pair(y, x));
					dis[y][x] = dis[node.first][node.second] + 1;
				}
			}
		}
		y = node.first;
		x = node.second - 1;
		if (dis[y][x] == 0)
		{
			if (maze[y][x])
			{
				if (y == n && x == m)
				{
					routes.push_back(dis[node.first][node.second] + 1);
				}
				else
				{
					q.push(make_pair(y, x));
					dis[y][x] = dis[node.first][node.second] + 1;
				}
			}
		}
		q.pop();
		if (q.empty())
		{
			break;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++)
		{
			int in = input[j - 1] - '0';
			if (in)
			{
				maze[i][j] = 1;
			}
		}
	}
	bfs(1, 1);
	sort(routes.begin(), routes.end());
	cout << routes.front() << '\n';
	return 0;
}