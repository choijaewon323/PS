#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

#define ALIVE 1
#define DEAD -1

struct Shark {
	int state;
	int num;
	int y;
	int x;
	int velocity;
	int direction;
	int size;
};

struct Pos {
	int y;
	int x;
	int direction;
};

int R, C, M;
vector<vector<int>> matrix;
Shark sharks[10001];

Pos move(int y, int x, int direction, int rest) {
	int left, right, up, down;
	
	switch (direction) {
	case LEFT:
		left = x - 1;
		if (rest > left) {
			return move(y, 1, RIGHT, rest - left);
		} else {
			int resX = x - rest;
			return { y, resX, direction };
		}
		break;
	case RIGHT:
		right = C - x;
		if (rest > right) {
			return move(y, C, LEFT, rest - right);
		} else {
			int resX = x + rest;
			return { y, resX, direction };
		}
		break;
	case UP:
		up = y - 1;
		if (rest > up) {
			return move(1, x, DOWN, rest - up);
		} else {
			int resY = y - rest;
			return { resY, x, direction };
		}
		break;
	case DOWN:
		down = R - y;
		if (rest > down) {
			return move(R, x, UP, rest - down);
		} else {
			int resY = y + rest;
			return { resY, x, direction };
		}
		break;
	}

	return { -1, -1, -1 };
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;
	matrix = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[i] = { ALIVE, i, r, c, s, d, z };
		matrix[r][c] = i;
	}

	int answer = 0;
	for (int king = 1; king <= C; king++) {
		// catch shark
		for (int y = 1; y <= R; y++) {
			if (matrix[y][king] != 0) {
				int sharkNum = matrix[y][king];
				Shark &presentShark = sharks[sharkNum];
				answer += presentShark.size;
				matrix[y][king] = 0;
				presentShark.state = DEAD;
				break;
			}
		}

		// shark move
		vector<vector<int>> temp(R + 1, vector<int>(C + 1, 0));
		
		for (int i = 1; i <= M; i++) {
			if (sharks[i].state == DEAD) {
				continue;
			}

			int num = i;
			Shark &presentShark = sharks[num];
			int direction = presentShark.direction;
			int v = presentShark.velocity;
			int y = presentShark.y;
			int x = presentShark.x;

			Pos next = move(y, x, direction, v);

			if (temp[next.y][next.x] == 0) {
				temp[next.y][next.x] = num;
				presentShark.y = next.y;
				presentShark.x = next.x;
				presentShark.direction = next.direction;
			} else {
				int nextNum = temp[next.y][next.x];
				Shark &oppoShark = sharks[nextNum];

				if (oppoShark.size > presentShark.size) {
					presentShark.state = DEAD;
				} else {
					oppoShark.state = DEAD;
					temp[next.y][next.x] = num;
					presentShark.y = next.y;
					presentShark.x = next.x;
					presentShark.direction = next.direction;
				}
			}
		}
		
		matrix = temp;
	}

	cout << answer << '\n';

	return 0;
}