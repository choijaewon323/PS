#include <iostream>
#include <vector>
using namespace std;

#define MAX 20
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

#define ABOVE 0
#define BELOW 1
#define EAST 2
#define NORTH 3
#define WEST 4
#define SOUTH 5

vector<int> dice(6, 0);
int matrix[MAX][MAX];
int N, M, K;

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

void moveDice(int direction) {
	vector<int> result(6, 0);

	switch (direction) {
	case LEFT:
		result[ABOVE] = dice[EAST];
		result[BELOW] = dice[WEST];
		result[EAST] = dice[BELOW];
		result[NORTH] = dice[NORTH];
		result[WEST] = dice[ABOVE];
		result[SOUTH] = dice[SOUTH];
		break;
	case RIGHT:
		result[ABOVE] = dice[WEST];
		result[BELOW] = dice[EAST];
		result[EAST] = dice[ABOVE];
		result[NORTH] = dice[NORTH];
		result[WEST] = dice[BELOW];
		result[SOUTH] = dice[SOUTH];
		break;
	case UP:
		result[ABOVE] = dice[SOUTH];
		result[BELOW] = dice[NORTH];
		result[EAST] = dice[EAST];
		result[NORTH] = dice[ABOVE];
		result[WEST] = dice[WEST];
		result[SOUTH] = dice[BELOW];
		break;
	case DOWN:
		result[ABOVE] = dice[NORTH];
		result[BELOW] = dice[SOUTH];
		result[EAST] = dice[EAST];
		result[NORTH] = dice[BELOW];
		result[WEST] = dice[WEST];
		result[SOUTH] = dice[ABOVE];
		break;
	}

	dice = result;
}

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M) {
		return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int initY, initX;

	cin >> N >> M >> initY >> initX >> K;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> matrix[y][x];
		}
	}

	int y = initY;
	int x = initX;
	for (int i = 0; i < K; i++) {
		int command;
		cin >> command;

		pair<int, int> next = nextPos(y, x, command);
		
		if (!inRange(next.first, next.second)) {
			continue;
		}

		y = next.first;
		x = next.second;

		// 1. move dice
		moveDice(command);
		
		// 2. copy
		if (matrix[next.first][next.second] == 0) {
			matrix[next.first][next.second] = dice[BELOW];
		} else {
			dice[BELOW] = matrix[next.first][next.second];
			matrix[next.first][next.second] = 0;
		}

		cout << dice[ABOVE] << '\n';
	}

	return 0;
}