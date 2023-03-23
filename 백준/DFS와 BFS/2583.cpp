#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define MAX 100

int m, n, k;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
bool paper[MAX + 1][MAX + 1];

bool inRange(int y, int x)
{
	if (0 <= y && y < m && 0 <= x && x < n)
	{
		return true;
	}
	return false;
}

int bfs(int startY, int startX)
{
	queue<pair<int, int>> q;
	int result = 1;
	paper[startY][startX] = false;
	q.push(make_pair(startY, startX));

	while (!q.empty())
	{
		int presentY = q.front().first;
		int presentX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = presentY + dy[i];
			int nextX = presentX + dx[i];

			if (inRange(nextY, nextX) && paper[nextY][nextX])
			{
				paper[nextY][nextX] = false;
				result++;
				q.push(make_pair(nextY, nextX));
			}
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < MAX + 1; y++)
	{
		for (int x = 0; x < MAX + 1; x++)
		{
			paper[y][x] = true;
		}
	}

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y <= y2 - 1; y++)
		{
			for (int x = x1; x <= x2 - 1; x++)
			{
				paper[y][x] = false;
			}
		}
	}

	vector<int> answer;
	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (paper[y][x])
			{
				int result = bfs(y, x);
				answer.push_back(result);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (auto i : answer)
	{
		cout << i << " ";
	}
	cout << '\n';

	return 0;
}