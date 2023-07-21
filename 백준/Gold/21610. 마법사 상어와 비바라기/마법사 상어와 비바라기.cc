#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define LEFT 1
#define UPLEFT 2
#define UP 3
#define UPRIGHT 4
#define RIGHT 5
#define DOWNRIGHT 6
#define DOWN 7
#define DOWNLEFT 8

int N, M;
int buckets[50][50];
pair<int, int> moveCommand[100];
vector<pair<int, int>> clouds;
int dy[] = { -1, 1, 1, -1 };
int dx[] = { -1, -1, 1, 1 };

bool inRange(int y, int x)
{
	if (0 <= y && y < N && 0 <= x && x < N)
	{
		return true;
	}
	return false;
}

pair<int, int> nextPosition(int y, int x, int direction, int speed)
{
	int nextY = y, nextX = x;

	switch (direction)
	{
	case LEFT:
		nextX = (nextX - speed) % N;
		if (nextX < 0)
		{
			nextX += N;
		}
		
		break;

	case UPLEFT:
		nextY = (nextY - speed) % N;
		if (nextY < 0)
		{
			nextY += N;
		}
		nextX = (nextX - speed) % N;
		if (nextX < 0)
		{
			nextX += N;
		}
		break;

	case UP:
		nextY = (nextY - speed) % N;
		if (nextY < 0)
		{
			nextY += N;
		}
		break;

	case UPRIGHT:
		nextY = (nextY - speed) % N;
		if (nextY < 0)
		{
			nextY += N;
		}
		nextX = (nextX + speed) % N;
		break;

	case RIGHT:
		nextX = (nextX + speed) % N;
		break;

	case DOWNRIGHT:
		nextY = (nextY + speed) % N;
		nextX = (nextX + speed) % N;
		break;

	case DOWN:
		nextY = (nextY + speed) % N;
		break;

	case DOWNLEFT:
		nextY = (nextY + speed) % N;
		nextX = (nextX - speed) % N;
		if (nextX < 0)
		{
			nextX += N;
		}
		break;
	}

	return { nextY, nextX };
}

bool isDeleted(int y, int x, vector<pair<int, int>> &tempPosition)
{
	for (auto &pos : tempPosition)
	{
		if (y == pos.first && x == pos.second)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> buckets[y][x];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int d, s;

		cin >> d >> s;

		moveCommand[i] = { d,s };
	}

	// 비바라기
	clouds.push_back({ N - 1, 0 });
	clouds.push_back({ N - 1, 1 });
	clouds.push_back({ N - 2, 0 });
	clouds.push_back({ N - 2, 1 });

	for (int i = 0; i < M; i++)
	{
		pair<int, int> presentCommand = moveCommand[i];
		int d = presentCommand.first;
		int s = presentCommand.second;
		vector<pair<int, int>> tempPosition;

		// 1 구름 이동, 2 물의 양 증가
		for (auto &cloud : clouds)
		{
			pair<int, int> next = nextPosition(cloud.first, cloud.second, d, s);
			cloud.first = next.first;
			cloud.second = next.second;
			buckets[cloud.first][cloud.second] += 1;
			tempPosition.push_back({ cloud.first, cloud.second });
		}
		
		// 3 구름 사라짐
		clouds.clear();

		// 4 물복사버그
		for (auto &pos : tempPosition)
		{
			int y = pos.first;
			int x = pos.second;
			int cnt = 0;

			for (int i = 0; i < 4; i++)
			{
				int nextY = y + dy[i];
				int nextX = x + dx[i];

				if (inRange(nextY, nextX) && buckets[nextY][nextX] > 0)
				{
					cnt++;
				}
			}

			buckets[y][x] += cnt;
		}

		// 5 구름 생성, 물의 양 2 감소
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (buckets[y][x] >= 2 && !isDeleted(y, x, tempPosition))
				{
					clouds.push_back({ y, x });
					buckets[y][x] -= 2;
				}
			}
		}
	}

	// 물의 합
	int answer = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			answer += buckets[y][x];
		}
	}

	cout << answer << '\n';

	return 0;
}