#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3
#define MAX 100

vector<int> dragon[4][11];
bool matrix[MAX + 1][MAX + 1];
int N;

int roll(int direction) {
	switch (direction) {
	case RIGHT:
		return UP;
	case UP:
		return LEFT;
	case LEFT:
		return DOWN;
	case DOWN:
		return RIGHT;
	}

	return -1;
}

void counterClock(vector<int> &prevReverse) {
	int size = prevReverse.size();

	for (int i = 0; i < size; i++) {
		prevReverse[i] = roll(prevReverse[i]);
	}
}

void init() {
	for (int i = 0; i < 4; i++) {
		dragon[i][0] = { i };
	}

	for (int direction = 0; direction < 4; direction++) {
		for (int generation = 1; generation <= 10; generation++) {
			vector<int> prevOrigin = dragon[direction][generation - 1];
			vector<int> prevReverse = dragon[direction][generation - 1];

			reverse(prevReverse.begin(), prevReverse.end());
			counterClock(prevReverse);
			
			for (int p : prevOrigin) {
				dragon[direction][generation].push_back(p);
			}
			for (int p : prevReverse) {
				dragon[direction][generation].push_back(p);
			}
		}
	}
}

pair<int, int> nextPos(int y, int x, int direction) {
	switch (direction) {
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}

	return { y, x };
}

bool inRange(int y, int x) {
	if (0 <= y && y <= MAX && 0 <= x && x <= MAX) {
		return true;
	}
	return false;
}

void dragonCurve(int y, int x, int d, int g) {
	vector<int>& presentDragon = dragon[d][g];

	matrix[y][x] = true;
	
	for (int direction : presentDragon) {
		pair<int, int> next = nextPos(y, x, direction);

		int ny = next.first;
		int nx = next.second;

		if (!inRange(ny, nx)) {
			break;
		}

		y = ny;
		x = nx;
		matrix[ny][nx] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		dragonCurve(y, x, d, g);
	}

	int answer = 0;

	for (int y = 0; y <= MAX - 1; y++) {
		for (int x = 0; x <= MAX - 1; x++) {
			bool leftUp = matrix[y][x];
			bool rightUp = matrix[y][x + 1];
			bool leftDown = matrix[y + 1][x];
			bool rightDown = matrix[y + 1][x + 1];

			if (leftUp && rightUp && leftDown && rightDown) {
				answer++;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}