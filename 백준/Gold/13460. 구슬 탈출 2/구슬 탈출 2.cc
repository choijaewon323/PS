#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

#define BLANK '.'
#define WALL '#'
#define HOLE 'O'
#define RED 'R'
#define BLUE 'B'

#define LEFT 1
#define UP 2
#define RIGHT 3
#define DOWN 4

#define MAX 10000

pair<int, int> nextPos(vector<vector<char>>& board, int y, int x, int direction)
{
	if (board[y][x] == HOLE)
	{
		return { y, x };
	}

	switch (direction)
	{
	case LEFT:
		while (true)
		{
			if (board[y][x - 1] == BLANK)
			{
				x--;
			}
			else if (board[y][x - 1] == HOLE)
			{
				x--;
				break;
			}
			else
			{
				break;
			}
		}

		break;
	case UP:
		while (true)
		{
			if (board[y - 1][x] == BLANK)
			{
				y--;
			}
			else if (board[y - 1][x] == HOLE)
			{
				y--;
				break;
			}
			else
			{
				break;
			}
		}

		break;
	case RIGHT:
		while (true)
		{
			if (board[y][x + 1] == BLANK)
			{
				x++;
			}
			else if (board[y][x + 1] == HOLE)
			{
				x++;
				break;
			}
			else
			{
				break;
			}
		}

		break;
	case DOWN:
		while (true)
		{
			if (board[y + 1][x] == BLANK)
			{
				y++;
			}
			else if (board[y + 1][x] == HOLE)
			{
				y++;
				break;
			}
			else
			{
				break;
			}
		}

		break;
	}

	return { y, x };
}

int solution(vector<vector<char>> board, int stage, pair<int, int> red, pair<int, int> blue)
{
	if (stage > 10)
	{
		return MAX;
	}

	int answer = MAX;
	for (int direction = 1; direction <= 4; direction++)
	{
		vector<vector<char>> tempBoard = board;
		pair<int, int> redNext = red;
		pair<int, int> blueNext = blue;

		bool redHole = false;
		bool blueHole = false;
		bool redMove = false;
		bool blueMove = false;

		// 1. red move
		redNext = nextPos(tempBoard, red.first, red.second, direction);

		if (redNext != red)
		{
			if (tempBoard[redNext.first][redNext.second] == HOLE)
			{
				redHole = true;
				redMove = true;
				tempBoard[red.first][red.second] = BLANK;
			}
			else
			{
				redMove = true;
				tempBoard[red.first][red.second] = BLANK;
				tempBoard[redNext.first][redNext.second] = RED;
			}
		}

		// 2. blue move
		blueNext = nextPos(tempBoard, blue.first, blue.second, direction);

		if (blueNext != blue)
		{
			if (tempBoard[blueNext.first][blueNext.second] == HOLE)
			{
				blueHole = true;
				blueMove = true;
				tempBoard[blue.first][blue.second] = BLANK;
			}
			else
			{
				blueMove = true;
				tempBoard[blue.first][blue.second] = BLANK;
				tempBoard[blueNext.first][blueNext.second] = BLUE;
			}
		}

		// 3. if red no move, red move again
		pair<int, int> tempRed = redNext;
			redNext = nextPos(tempBoard, tempRed.first, tempRed.second, direction);

			if (redNext != tempRed)
			{
				if (tempBoard[redNext.first][redNext.second] == HOLE)
				{
					redHole = true;
					redMove = true;
					tempBoard[tempRed.first][tempRed.second] = BLANK;
				}
				else
				{
					redMove = true;
					tempBoard[tempRed.first][tempRed.second] = BLANK;
					tempBoard[redNext.first][redNext.second] = RED;
				}
			}
		

		// 4. if blue no move, blue move again
		pair<int, int> tempBlue = blueNext;
			blueNext = nextPos(tempBoard, tempBlue.first, tempBlue.second, direction);

			if (blueNext != blue)
			{
				if (tempBoard[blueNext.first][blueNext.second] == HOLE)
				{
					blueHole = true;
					blueMove = true;
					tempBoard[tempBlue.first][tempBlue.second] = BLANK;
				}
				else
				{
					blueMove = true;
					tempBoard[tempBlue.first][tempBlue.second] = BLANK;
					tempBoard[blueNext.first][blueNext.second] = BLUE;
				}
			}
		

		if (!redMove && !blueMove)
		{
			continue;
		}

		// check hole
		if (redHole && !blueHole)
		{
			// success
			return stage;
		}
		else if ((redHole && blueHole) || (!redHole && blueHole))
		{
			// fail
			continue;
		}
		else if (!redHole && !blueHole)
		{
			// continue
			answer = min(answer, solution(tempBoard, stage + 1, redNext, blueNext));
		}
	}

	return answer;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));

	pair<int, int> red, blue;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			char temp;

			cin >> temp;

			board[y][x] = temp;

			if (temp == RED)
			{
				red = { y, x };
			}
			if (temp == BLUE)
			{
				blue = { y,x };
			}
		}
	}

	int answer = solution(board, 1, red, blue);

	if (answer == MAX)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << answer << '\n';
	}

	return 0;
}