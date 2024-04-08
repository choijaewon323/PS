#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
#define HOLE 'O'
#define WALL '#'
#define EMPTY '.'
#define RED 'R'
#define BLUE 'B'
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

struct Ball {
	int redY;
	int redX;
	int blueY;
	int blueX;
};

int N, M;
vector<vector<char>> board;
Ball init;

void input() {
	cin >> N >> M;
	board = vector<vector<char>>(N, vector<char>(M));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
			
			if (board[y][x] == RED) {
				board[y][x] = EMPTY;
				init.redY = y;
				init.redX = x;
			} else if (board[y][x] == BLUE) {
				board[y][x] = EMPTY;
				init.blueY = y;
				init.blueX = x;
			}
		}
	}
}

pair<int, int> nextPos(int y, int x, int direction) {
	switch (direction) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	return { y, x };
}

pair<int, int> moveOneBall(int y, int x, int direction, pair<int, int> oppo) {
	pair<int, int> present = { y, x };
	while (true) {
		pair<int, int> next = nextPos(present.first, present.second, direction);

		char state = board[next.first][next.second];

		if (state == '#') {
			return present;
		}

		if (state == 'O') {
			return { -1, -1 };
		}

		if (next.first == oppo.first && next.second == oppo.second) {
			return present;
		}

		present = next;
	}
}

Ball move(Ball ball, int direction) {
	switch (direction) {
	case LEFT:
		if (ball.redX <= ball.blueX) {
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, {ball.blueY, ball.blueX});
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, red);
			return { red.first, red.second, blue.first, blue.second };
		} else {
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, { ball.redY, ball.redX });
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, blue);
			return { red.first, red.second, blue.first, blue.second };
		}
		break;
	case RIGHT:
		if (ball.redX >= ball.blueX) {
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, { ball.blueY, ball.blueX });
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, red);
			return { red.first, red.second, blue.first, blue.second };
		} else {
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, { ball.redY, ball.redX });
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, blue);
			return { red.first, red.second, blue.first, blue.second };
		}
		break;
	case UP:
		if (ball.redY <= ball.blueY) {
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, { ball.blueY, ball.blueX });
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, red);
			return { red.first, red.second, blue.first, blue.second };
		} else {
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, { ball.redY, ball.redX });
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, blue);
			return { red.first, red.second, blue.first, blue.second };
		}
		break;
	case DOWN:
		if (ball.redY >= ball.blueY) {
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, { ball.blueY, ball.blueX });
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, red);
			return { red.first, red.second, blue.first, blue.second };
		} else {
			pair<int, int> blue = moveOneBall(ball.blueY, ball.blueX, direction, { ball.redY, ball.redX });
			pair<int, int> red = moveOneBall(ball.redY, ball.redX, direction, blue);
			return { red.first, red.second, blue.first, blue.second };
		}
		break;
	}

	return { -1, -1, -1, -1 };
}

int func(Ball ball) {
	queue<pair<Ball, int>> q;
	
	q.push({ ball, 0 });

	while (!q.empty()) {
		Ball presentBall = q.front().first;
		int presentCnt = q.front().second;
		q.pop();

		if (presentCnt == 10) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			Ball next = move(presentBall, i);
			
			if (next.blueY == -1) {
				continue;
			}

			if (next.redY == -1) {
				return presentCnt + 1;
			}

			q.push({ next, presentCnt + 1 });
		}
	}

	return -1;
}

int solve() {
	int result = func(init);

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}