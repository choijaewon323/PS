#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

typedef struct _horse
{
	int y;
	int x;
	int direction;
} horse;

horse horses[11];
int board[12][12];
stack<int> horsePosition[12][12];
int n, k;

pair<int, int> nextPosition(int y, int x, int direction)
{
	int resultY = y, resultX = x;

	switch (direction)
	{
	case RIGHT:
		resultX++;
		break;
	case LEFT:
		resultX--;
		break;

	case UP:
		resultY--;
		break;

	case DOWN:
		resultY++;
		break;
	}

	return { resultY, resultX };
}

int oppositeDirection(int direction)
{
	switch (direction)
	{
	case RIGHT:
		return LEFT;
	case LEFT:
		return RIGHT;
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	}
}

bool inRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
	{
		return true;
	}
	return false;
}

void input()
{
	cin >> n >> k;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> board[y][x];
		}
	}

	for (int i = 1; i <= k; i++)
	{
		int y, x, d;

		cin >> y >> x >> d;
		horses[i] = { y - 1, x - 1, d };
		horsePosition[y - 1][x - 1].push(i);
	}
}

bool isFour()
{
	// check whether four
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (horsePosition[y][x].size() >= 4)
			{
				return true;
			}
		}
	}

	return false;
}

void moveHorse(int horseNum)
{
	horse present = horses[horseNum];
	int y = present.y;
	int x = present.x;
	int direction = present.direction;
	vector<int> tempHorses;

	// pop from stack
	while (!(horsePosition[y][x].empty()))
	{
		int temp = horsePosition[y][x].top();
		horsePosition[y][x].pop();

		tempHorses.push_back(temp);

		if (temp == horseNum)
		{
			break;
		}
	}

	// next position
	pair<int, int> nextPos = nextPosition(y, x, direction);
	int nextY = nextPos.first;
	int nextX = nextPos.second;


	// move
	if (inRange(nextY, nextX))
	{
		int nextColor = board[nextY][nextX];

		switch (nextColor)
		{
		case WHITE:
			reverse(tempHorses.begin(), tempHorses.end());

			for (int h : tempHorses)
			{
				horsePosition[nextY][nextX].push(h);
				horses[h].y = nextY;
				horses[h].x = nextX;
			}

			break;

		case RED:
			for (int h : tempHorses)
			{
				horsePosition[nextY][nextX].push(h);
				horses[h].y = nextY;
				horses[h].x = nextX;
			}

			break;

		case BLUE:
			// 1. change direction
			horses[horseNum].direction = oppositeDirection(direction);
			
			pair<int, int> next = nextPosition(y, x, horses[horseNum].direction);
			bool in = inRange(next.first, next.second);
			
			// 2. if next is not blue, move
			if (in && board[next.first][next.second] != BLUE)
			{
				switch (board[next.first][next.second])
				{
				case WHITE:
					reverse(tempHorses.begin(), tempHorses.end());

					for (int h : tempHorses)
					{
						horsePosition[next.first][next.second].push(h);
						horses[h].y = next.first;
						horses[h].x = next.second;
					}
					break;
				
				case RED:
					for (int h : tempHorses)
					{
						horsePosition[next.first][next.second].push(h);
						horses[h].y = next.first;
						horses[h].x = next.second;
					}

					break;
				}
			}

			// 2.1 if next is blue or out, no move
			if ((in && board[next.first][next.second] == BLUE) || !in)
			{
				// empty
				reverse(tempHorses.begin(), tempHorses.end());

				for (int h : tempHorses)
				{
					horsePosition[y][x].push(h);
					horses[h].y = y;
					horses[h].x = x;
				}
			}

			break;
		}
	}
	else
	{
		// 1. change direction
		horses[horseNum].direction = oppositeDirection(direction);

		pair<int, int> next = nextPosition(y, x, horses[horseNum].direction);
		bool in = inRange(next.first, next.second);

		// 2. if next is not blue, move
		if (in && board[next.first][next.second] != BLUE)
		{
			switch (board[next.first][next.second])
			{
			case WHITE:
				reverse(tempHorses.begin(), tempHorses.end());

				for (int h : tempHorses)
				{
					horsePosition[next.first][next.second].push(h);
					horses[h].y = next.first;
					horses[h].x = next.second;
				}
				break;

			case RED:
				for (int h : tempHorses)
				{
					horsePosition[next.first][next.second].push(h);
					horses[h].y = next.first;
					horses[h].x = next.second;
				}

				break;
			}
		}

		// 2.1 if next is blue or out, no move
		if ((in && board[next.first][next.second] == BLUE) || !in)
		{
			// empty
			reverse(tempHorses.begin(), tempHorses.end());

			for (int h : tempHorses)
			{
				horsePosition[y][x].push(h);
				horses[h].y = y;
				horses[h].x = x;
			}
		}
	}
}

void print()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << horsePosition[y][x].size() << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int answer = -1;
	bool correct = false;

	input();

	for (int turn = 1; turn <= 1000; turn++)
	{
		for (int h = 1; h <= k; h++)
		{

			// 1. move
			moveHorse(h);

			// 2. check four
			if (isFour())
			{
				correct = true;
				answer = turn;
				break;
			}
		}

		if (correct)
		{
			break;
		}
	}

	if (correct)
	{
		cout << answer << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}

	return 0;
}