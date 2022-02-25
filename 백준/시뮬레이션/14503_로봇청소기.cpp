#include <iostream>
using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int area[52][52];
int n, m;

int func(int startR, int startC, int dir) {
	int y = startR;
	int x = startC;
	int direction;
	int result = 0;
	
	switch (dir) {
	case 0:
		direction = NORTH;
		break;
	case 1:
		direction = EAST;
		break;
	case 2:
		direction = SOUTH;
		break;
	default:
		direction = WEST;
	}

	while (true) {
		// 1. 현재 위치 청소
		if (area[y][x] == 0) {
			area[y][x] = 2;
			result++;
		}
		
		if (direction == NORTH) {
			if (area[y][x - 1] != 0 &&
				area[y + 1][x] != 0 &&
				area[y][x + 1] != 0 &&
				area[y - 1][x] != 0) {
				// 2-c
				if (area[y + 1][x] == 2) {
					y = y + 1;
					continue;
				}
				// 2-d
				else {
					break;
				}
			}
			// 2-a
			else if (area[y][x - 1] == 0) {
				x = x - 1;
				direction = WEST;
				continue;
			}
			// 2-b
			else if (area[y][x - 1] != 0) {
				direction = WEST;
				continue;
			}
		}
		else if (direction == WEST) {
			if (area[y][x - 1] != 0 &&
				area[y + 1][x] != 0 &&
				area[y][x + 1] != 0 &&
				area[y - 1][x] != 0) {
				// 2-c
				if (area[y][x + 1] == 2) {
					x = x + 1;
					continue;
				}
				// 2-d
				else {
					break;
				}
			}
			// 2-a
			else if (area[y + 1][x] == 0) {
				y = y + 1;
				direction = SOUTH;
				continue;
			}
			// 2-b
			else if (area[y + 1][x] != 0) {
				direction = SOUTH;
				continue;
			}
		}
		else if (direction == SOUTH) {
			if (area[y][x - 1] != 0 &&
				area[y + 1][x] != 0 &&
				area[y][x + 1] != 0 &&
				area[y - 1][x] != 0) {
				// 2-c
				if (area[y - 1][x] == 2) {
					y = y - 1;
					continue;
				}
				// 2-d
				else {
					break;
				}
			}
			// 2-a
			if (area[y][x + 1] == 0) {
				x = x + 1;
				direction = EAST;
				continue;
			}
			// 2-b
			else if (area[y][x + 1] != 0) {
				direction = EAST;
				continue;
			}
		}
		if (direction == EAST) {
			if (area[y][x - 1] != 0 &&
				area[y + 1][x] != 0 &&
				area[y][x + 1] != 0 &&
				area[y - 1][x] != 0) {
				// 2-c
				if (area[y][x - 1] == 2) {
					x = x - 1;
					continue;
				}
				// 2-d
				else {
					break;
				}
			}
			// 2-a
			if (area[y - 1][x] == 0) {
				y = y - 1;
				direction = NORTH;
				continue;
			}
			// 2-b
			else if (area[y - 1][x] != 0) {
				direction = NORTH;
				continue;
			}
		}
	}

	return result;
}

int main() {
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			area[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> area[i][j];
		}
	}

	int result = func(r + 1, c + 1, d);

	cout << result << '\n';

	return 0;
}