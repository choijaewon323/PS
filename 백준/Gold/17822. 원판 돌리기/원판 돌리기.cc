#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define CLOCK 0
#define COUNTERCLOCK 1

int circle[50][50];
int N, M, T;

void roll(int direction, int k, int r)
{
	vector<int> temp(M);

	switch (direction)
	{
	case CLOCK:
		for (int i = 0; i < M; i++)
		{
			int index = (i + k) % M;

			temp[index] = circle[r][i];
		}

		for (int i = 0; i < M; i++)
		{
			circle[r][i] = temp[i];
		}

		break;
	case COUNTERCLOCK:
		for (int i = 0; i < M; i++)
		{
			int index = (i - k) % M;
			if (index < 0)
			{
				index += M;
			}

			temp[index] = circle[r][i];
		}

		for (int i = 0; i < M; i++)
		{
			circle[r][i] = temp[i];
		}

		break;
	}
}

void print()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << circle[y][x] << " ";
		}
		cout << '\n';
	}
}

bool inRange(int y, int x)
{
	if (0 <= y && y < N && 0 <= x && x < M)
	{
		return true;
	}
	return false;
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void bfs(int startY, int startX, int num)
{
	circle[startY][startX] = -1;
	queue<pair<int, int>> q;
	q.push({ startY, startX });

	while (!q.empty())
	{
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = present.first + dy[i];
			int nx = present.second + dx[i];

			nx %= M;

			if (nx < 0)
			{
				nx += M;
			}

			if (inRange(ny, nx) && num == circle[ny][nx])
			{
				circle[ny][nx] = -1;
				q.push({ ny, nx });
			}
		}
	}
}

void findAdjacent()
{
	bool isAdjacent = false;

	int acc = 0;
	int cnt = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (circle[y][x] == -1)
			{
				continue;
			}

			acc += circle[y][x];
			cnt++;
			vector<pair<int, int>> temp;
			bool check = false;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				nx %= M;

				if (nx < 0)
				{
					nx += M;
				}

				if (inRange(ny, nx) && circle[y][x] == circle[ny][nx])
				{
					isAdjacent = true;
					check = true;
					break;
				}
			}

			if (check)
			{
				bfs(y, x, circle[y][x]);
			}
		}
	}

	if (!isAdjacent)
	{
		double aver = acc / (double)cnt;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (circle[y][x] == -1)
				{
					continue;
				}

				if (circle[y][x] < aver)
				{
					circle[y][x]++;
				}
				else if (circle[y][x] > aver)
				{
					circle[y][x]--;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> circle[i][j];
		}
	}

	for (int t = 0; t < T; t++)
	{
		int x, d, k;

		cin >> x >> d >> k;

		// 1. roll
		for (int i = x; i <= N; i += x)
		{
			roll(d, k, i - 1);
		}

		// 2. find circle adjacent 
		findAdjacent();
	}

	int acc = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (circle[y][x] == -1)
			{
				continue;
			}

			acc += circle[y][x];
		}
	}

	cout << acc << '\n';

	return 0;
}