#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

#define MAX 12
#define HORSE_MAX 10
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define WHITE 0
#define RED 1
#define BLUE 2

struct Horse {
	int y;
	int x;
	int direction;
};

int N, K;
int board[MAX + 1][MAX + 1];
Horse horseInfo[HORSE_MAX + 1];
stack<int> state[MAX + 1][MAX + 1];

void input() {
	cin >> N >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> board[y][x];
		}
	}
	for (int i = 1; i <= K; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		horseInfo[i] = { y, x, d };
		state[y][x].push(i);
	}
}

bool isEnd() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (state[y][x].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

pair<int, int> nextPos(int y, int x, int direction) {
	switch (direction) {
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
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

bool inRange(int y, int x) {
	if (1 <= y && y <= N && 1 <= x && x <= N) {
		return true;
	}
	return false;
}

int opposite(int direction) {
	switch (direction) {
	case RIGHT:
		return LEFT;
	case LEFT:
		return RIGHT;
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	}
	return -1;
}

void move(int horseNum, bool twice) {
	vector<int> horses;	// 앞부터 위에 있는 것
	Horse present = horseInfo[horseNum];
	int y = present.y;
	int x = present.x;
	int direction = present.direction;

	while (!state[y][x].empty()) {
		int temp = state[y][x].top();
		state[y][x].pop();

		if (temp == horseNum) {
			horses.push_back(temp);
			break;
		}
		horses.push_back(temp);
	}
	pair<int, int> next = nextPos(y, x, direction);
	if (inRange(next.first, next.second)) {
		if (board[next.first][next.second] == WHITE) {
			for (int i = horses.size() - 1; i >= 0; i--) {
				int num = horses[i];
				horseInfo[num].y = next.first;
				horseInfo[num].x = next.second;
				state[next.first][next.second].push(num);
			}
		} else if (board[next.first][next.second] == RED) {
			for (int i = 0; i < horses.size(); i++) {
				int num = horses[i];
				horseInfo[num].y = next.first;
				horseInfo[num].x = next.second;
				state[next.first][next.second].push(num);
			}
		} else if (board[next.first][next.second] == BLUE) {
			if (!twice) {
				horseInfo[horseNum].direction = opposite(direction);
				for (int i = horses.size() - 1; i >= 0; i--) {
					int num = horses[i];
					state[y][x].push(num);
				}
				move(horseNum, true);
			} else {
				for (int i = horses.size() - 1; i >= 0; i--) {
					int num = horses[i];
					state[y][x].push(num);
				}
			}
		}
	} else {	// blue
		if (!twice) {
			horseInfo[horseNum].direction = opposite(direction);
			for (int i = horses.size() - 1; i >= 0; i--) {
				int num = horses[i];
				state[y][x].push(num);
			}
			move(horseNum, true);
		} else {
			for (int i = horses.size() - 1; i >= 0; i--) {
				int num = horses[i];
				state[y][x].push(num);
			}
		}
	}
}

int solve() {
	for (int turn = 1; turn <= 1000; turn++) {
		for (int h = 1; h <= K; h++) {
			// move
			move(h, false);

			// check
			if (isEnd()) {
				return turn;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';
	return 0;
}