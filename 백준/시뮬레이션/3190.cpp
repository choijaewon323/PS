#include <iostream>
#include <deque>
#include <utility>
using namespace std;

#define MAX 100

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

int n, k, l;
int board[MAX][MAX];
deque<pair<int, char>> q;

bool inRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
	{
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c;

		cin >> r >> c;
		board[r - 1][c - 1]++;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;

		cin >> x >> c;

		q.push_back(make_pair(x, c));
	}

	int sec = 0;
	int direction = RIGHT;
	deque<pair<int, int>> snake;
	snake.push_back(make_pair(0, 0));
	board[0][0] = -1;
	while (true)
	{
		sec++;
		pair<int, int> head = snake.front();

		// 몸길이 늘리기
		int nextY = head.first, nextX = head.second;
		switch (direction)
		{
		case RIGHT:
			nextX++;
			break;
		case LEFT:
			nextX--;
			break;
		case UP:
			nextY--;
			break;
		case DOWN:
			nextY++;
			break;
		}

		// 만약 자기 몸에 부딪히거나 칸을 벗어나면 종료
		if (!inRange(nextY, nextX))
		{
			break;
		}
		if (board[nextY][nextX] == -1)
		{
			break;
		}

		// 다음 칸 사과 판정
		if (board[nextY][nextX] == 1)
		{
			board[nextY][nextX] = -1;
			snake.push_front(make_pair(nextY, nextX));
		}
		else if (board[nextY][nextX] == 0)
		{
			board[nextY][nextX] = -1;
			snake.push_front(make_pair(nextY, nextX));
			
			pair<int, int> temp = snake.back();
			snake.pop_back();
			board[temp.first][temp.second] = 0;
		}

		// 방향 전환 정보
		if (!q.empty())
		{
			pair<int, char> change = q.front();

			if (change.first == sec)
			{
				q.pop_front();

				if (change.second == 'L')
				{
					switch (direction)
					{
					case RIGHT:
						direction = UP;
						break;
					case LEFT:
						direction = DOWN;
						break;
					case UP:
						direction = LEFT;
						break;
					case DOWN:
						direction = RIGHT;
						break;
					}
				}
				else if (change.second == 'D')
				{
					switch (direction)
					{
					case RIGHT:
						direction = DOWN;
						break;
					case LEFT:
						direction = UP;
						break;
					case UP:
						direction = RIGHT;
						break;
					case DOWN:
						direction = LEFT;
						break;
					}
				}
			}
		}
	}

	cout << sec << '\n';

	return 0;
}