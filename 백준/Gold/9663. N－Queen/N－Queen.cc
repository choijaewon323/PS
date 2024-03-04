#include <iostream>
#include <vector>
using namespace std;

int N;
int dy[] = { -1, 1, 1, -1 };
int dx[] = { -1, -1, 1, 1 };

int board[15][15];

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N) {
		return true;
	}
	return false;
}

void diagonal(int startY, int startX, int sy, int sx, int dist) {
	int ny = startY + sy;
	int nx = startX + sx;
	while (inRange(ny, nx)) {
		board[ny][nx] += dist;
		ny += sy;
		nx += sx;
	}
}

void queen(int startY, int startX, int dist) {
	board[startY][startX] += dist;

	for (int x = 0; x < N; x++) {
		if (x == startX) {
			continue;
		}
		board[startY][x] += dist;
	}
	for (int y = 0; y < N; y++) {
		if (y == startY) {
			continue;
		}
		board[y][startX] += dist;
	}

	for (int i = 0; i < 4; i++) {
		int sy = dy[i];
		int sx = dx[i];

		diagonal(startY, startX, sy, sx, dist);
	}
}

int solve(int y) {
	if (y == N) {
		return 1;
	}

	if (y == 0) {
		if (N % 2 == 0) {
			int result = 0;
			for (int x = 0; x < N / 2; x++) {
				if (!board[y][x]) {
					queen(y, x, 1);
					result += solve(y + 1);
					queen(y, x, -1);
				}
			}
			return result * 2;
		}
	}

	int result = 0;
	for (int x = 0; x < N; x++) {
		if (!board[y][x]) {
			queen(y, x, 1);
			result += solve(y + 1);
			queen(y, x, -1);
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cout << solve(0) << '\n';

	return 0;
}