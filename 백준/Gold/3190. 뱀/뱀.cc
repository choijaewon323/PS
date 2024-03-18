#include <iostream>
#include <deque>
#include <utility>
using namespace std;

#define TIME_MAX 10000
#define MAX 100
#define APPLE 2
#define SNAKE 1
#define EMPTY 0

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

int board[MAX + 1][MAX + 1];
int N;
char changeDirect[TIME_MAX + 1];

bool inRange(int y, int x) {
	if (1 <= y && y <= N && 1 <= x && x <= N) {
		return true;
	}

	return false;
}

bool isHit(int y, int x) {
	if (!inRange(y, x)) {
		return true;
	}

	if (board[y][x] == SNAKE) {
		return true;
	}

	return false;
}

pair<int, int> nextPos(int y, int x, int direction) {
	switch (direction) {
	case LEFT:
		x--;
		break;
	case UP:
		y--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	}

	return { y, x };
}

int solve() {
	int y = 1, x = 1;
	int direction = RIGHT;
	deque<pair<int, int>> snake;
	snake.push_back({ 1, 1 });
	board[1][1] = SNAKE;

	int second = 1;

	while (true) {
		// 1. snake move
		pair<int, int> next = nextPos(y, x, direction);

		// 1-1. if hit
		if (isHit(next.first, next.second)) {
			return second;
		}

		y = next.first;
		x = next.second;

		// 1-2 if apple
		if (board[next.first][next.second] == APPLE) {
			board[next.first][next.second] = SNAKE;
			snake.push_front(next);
		} else {	// 1-3 if not apple
			board[next.first][next.second] = SNAKE;
			snake.push_front(next);

			pair<int, int> tail = snake.back();
			snake.pop_back();
			
			board[tail.first][tail.second] = EMPTY;
		}

		// 2. change direction
		if (changeDirect[second] == 'L') {
			int nextDirect = (direction - 1) % 4;
			if (nextDirect < 0) {
				nextDirect += 4;
			}

			direction = nextDirect;
		} else if (changeDirect[second] == 'D') {
			int nextDirect = (direction + 1) % 4;
			direction = nextDirect;
		}

		// 3. increase second
		second++;
	}

	return second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;

		board[y][x] = APPLE;
	}
	int L;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time;
		char direct;
		cin >> time >> direct;

		changeDirect[time] = direct;
	}

	cout << solve() << '\n';

	return 0;
}