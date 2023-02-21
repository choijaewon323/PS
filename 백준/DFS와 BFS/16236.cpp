#include <iostream>
#include <queue>
using namespace std;

typedef struct _fish
{
	int fishSize;
	int y;
	int x;
} fish;

typedef struct _node
{
	int y;
	int x;
	int sec;
} node;

vector<fish> v;

int n;
int space[20][20];
int startY, startX, fishCount;
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

bool visited[20][20];
bool isEaten[400];

bool inRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < n)
	{
		return true;
	}
	return false;
}

int endY = 1000, endX = 1000;

int bfs(int startY, int startX, int sharkSize)
{
	queue<node> q;
	node start = { startY, startX, 0 };
	bool eat = false;
	int eatCount = -1;

	q.push(start);
	visited[start.y][start.x] = true;
	

	while (!q.empty())
	{
		node present = q.front();
		q.pop();

		if (space[present.y][present.x] < sharkSize &&
			space[present.y][present.x] > 0 && (!eat || eatCount == present.sec))
		{
			eat = true;
			eatCount = present.sec;

			if (endY > present.y)
			{
				endY = present.y;
				endX = present.x;
			}
			else if (endY == present.y)
			{
				if (endX > present.x)
				{
					endY = present.y;
					endX = present.x;
				}
			}

			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = present.y + dy[i];
			int nextX = present.x + dx[i];

			if (inRange(nextY, nextX) && !visited[nextY][nextX] &&
				space[nextY][nextX] <= sharkSize)
			{
				visited[nextY][nextX] = true;
				node next = { nextY, nextX, present.sec + 1 };
				q.push(next);
			}
		}
	}

	if (eat)
	{
		space[endY][endX] = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].y == endY && v[i].x == endX)
			{
				isEaten[i] = true;
				break;
			}
		}

		return eatCount;
	}
	else
	{
		return -1;
	}
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];

			if (space[i][j] >= 1 && space[i][j] <= 6)
			{
				fish newFish = { space[i][j], i, j };
				v.push_back(newFish);
				fishCount++;
			}
			if (space[i][j] == 9)
			{
				startY = i;
				startX = j;
				space[i][j] = 0;
			}
		}
	}
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == endY && j == endX)
			{
				cout << -1 << " ";
			}
			else
			{
				cout << space[i][j] << " ";
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

void solution()
{
	int eaten = 0;
	int tempEaten = 0;
	int tempSec = 0;
	int sharkSize = 2;
	int tempY = startY;
	int tempX = startX;

	while (1)
	{
		init();

		bool isFishExist = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (!isEaten[i] && sharkSize > v[i].fishSize)
			{
				isFishExist = true;
				break;
			}
		}

		if (!isFishExist)	// 먹을 수 있는 물고기가 없을 때
		{
			break;
		}
		else
		{
			endY = 1000;
			endX = 1000;
			int result = bfs(tempY, tempX, sharkSize);

			if (result == -1)	// 먹기 실패
			{
				break;
			}
			else
			{
				eaten++;
				tempEaten++;
				tempSec += result;
				tempY = endY;
				tempX = endX;

				if (tempEaten == sharkSize)
				{
					sharkSize++;
					tempEaten = 0;
				}

				if (eaten == fishCount)
				{
					break;
				}
			}
		}
	}

	cout << tempSec << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}