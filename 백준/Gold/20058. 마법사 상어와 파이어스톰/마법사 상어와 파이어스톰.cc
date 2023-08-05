#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int N, Q;
int A[64][64];
bool visited[64][64];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int pow(int n, int p)
{
	switch (p)
	{
	case 0:
		return 1;
	case 1:
		return 2;
	case 2:
		return 4;
	case 3:
		return 8;
	case 4:
		return 16;
	case 5:
		return 32;
	case 6:
		return 64;
	}
}

bool inRange(int y, int x)
{
	int num = pow(2, N);

	if (0 <= y && y < num && 0 <= x && x < num)
	{
		return true;
	}
	return false;
}

void divideAndRoll(int startY, int startX, int endY, int endX, int l)
{
	vector<vector<int>> result;

	for (int x = startX; x < endX; x++)
	{
		vector<int> temp;

		for (int y = endY - 1; y >= startY; y--)
		{
			temp.push_back(A[y][x]);
		}

		result.push_back(temp);
	}

	int indexY = 0, indexX = 0;
	for (int y = startY; y < endY; y++)
	{
		for (int x = startX; x < endX; x++)
		{
			A[y][x] = result[indexY][indexX++];
		}
		indexY++;
		indexX = 0;
	}
}

int bfs(int startY, int startX)
{
	queue<pair<int, int>> q;

	visited[startY][startX] = true;
	int cnt = 1;

	q.push({ startY, startX });

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = present.first + dy[i];
			int nx = present.second + dx[i];

			if (inRange(ny, nx) && !visited[ny][nx] && A[ny][nx] > 0)
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

void solve(int L)
{
	// 1. divide and roll
	int num = pow(2, N);
	int l = pow(2, L);
	for (int y = 0; y < num; y += l)
	{
		for (int x = 0; x < num; x += l)
		{
			divideAndRoll(y, x, y + l, x + l, l);
		}
	}

	// 2. find adjacent and melt
	vector<pair<int, int>> melt;

	for (int y = 0; y < num; y++)
	{
		for (int x = 0; x < num; x++)
		{
			if (A[y][x] > 0)
			{
				int cnt = 0;

				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (inRange(ny, nx) && A[ny][nx] > 0)
					{
						cnt++;
					}
				}

				if (cnt < 3)
				{
					melt.push_back({ y, x });
				}
			}
		}
	}

	for (auto &m : melt)
	{
		A[m.first][m.second]--;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;

	int num = pow(2, N);

	for (int y = 0; y < num; y++)
	{
		for (int x = 0; x < num; x++)
		{
			cin >> A[y][x];
		}
	}

	for (int q = 0; q < Q; q++)
	{
		int L;

		cin >> L;
		solve(L);
	}

	int answer1 = 0;
	int answer2 = 0;
	
	for (int y = 0; y < num; y++)
	{
		for (int x = 0; x < num; x++)
		{
			answer1 += A[y][x];

			if (!visited[y][x] && A[y][x] > 0)
			{
				answer2 = max(answer2, bfs(y, x));
			}
		}
	}

	cout << answer1 << '\n' << answer2 << '\n';
	
	return 0;
}