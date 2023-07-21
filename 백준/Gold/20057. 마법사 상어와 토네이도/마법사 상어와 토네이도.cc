#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

vector<int> speeds;
int N;
int matrix[499][499];

vector<pair<int, int>> sand[4];
double percent[] = { 0.02, 0.10, 0.07, 0.01, 0.05, 0.10, 0.07, 0.01, 0.02 };

void init()
{
	// 2 10 7 1 5 10 7 1 2
	sand[0] = {
		{-2, 0},{-1, -1},{-1, 0},{-1, 1},{0, -2},{1, -1},{1, 0},{1, 1},{2, 0}
	};

	sand[1] = {
		{0, -2}, {1, -1}, {0,-1}, {-1,-1}, {2,0}, {1,1}, {0,1}, {-1,1}, {0,2}
	};

	sand[2] = {
		{-2, 0}, {-1, 1}, {-1, 0}, {-1, -1}, {0, 2}, {1, 1}, {1, 0}, {1, -1}, {2, 0}
	};

	sand[3] = {
		{0, -2}, {-1,-1}, {0, -1}, {1, -1}, {-2, 0}, {-1, 1}, {0,1}, {1,1}, {0,2}
	};
}

pair<int, int> nextPosition(int y, int x, int direction)
{
	int nextY = y, nextX = x;

	switch (direction)
	{
	case LEFT:
		nextX--;
		break;

	case DOWN:
		nextY++;
		break;

	case RIGHT:
		nextX++;
		break;

	case UP:
		nextY--;
		break;
	}

	return { nextY, nextX };
}

bool inRange(int y, int x)
{
	if (0 <= y && y < N && 0 <= x && x < N)
	{
		return true;
	}
	return false;
}

int answer = 0;

void tornado(int startY, int startX)
{
	int y = startY, x = startX;
	int direction[] = { LEFT, DOWN, RIGHT, UP };
	int index = 0;

	for (int speed : speeds)
	{
		int tempDirect = direction[index];
		index++;
		index %= 4;

		for (int i = 0; i < speed; i++)
		{
			pair<int, int> next = nextPosition(y, x, tempDirect);
			y = next.first;
			x = next.second;

			// a 빼고 다 계산
			int tempSum = 0;
			for (int j = 0; j < sand[tempDirect].size(); j++)
			{
				int dy = y + sand[tempDirect][j].first;
				int dx = x + sand[tempDirect][j].second;
				double temp = percent[j] * matrix[y][x];
				tempSum += (int)temp;

				if (inRange(dy, dx))
				{
					matrix[dy][dx] += (int)temp;
				}
				else
				{
					answer += (int)temp;
				}
			}

			// a 계산
			int dy = y, dx = x;

			switch (tempDirect)
			{
			case LEFT:
				dx--;
				break;
			case DOWN:
				dy++;
				break;
			case RIGHT:
				dx++;
				break;
			case UP:
				dy--;
				break;
			}

			if (inRange(dy, dx))
			{
				matrix[dy][dx] += (matrix[y][x] - tempSum);
				matrix[y][x] = 0;
			}
			else
			{
				answer += (matrix[y][x] - tempSum);
				matrix[y][x] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> matrix[y][x];
		}
	}

	init();

	for (int i = 1; i <= N - 1; i++)
	{
		speeds.push_back(i);
		speeds.push_back(i);
	}
	speeds.push_back(N - 1);

	// 가운데
	int startY = N / 2, startX = N / 2;

	tornado(startY, startX);

	cout << answer << '\n';

	return 0;
}