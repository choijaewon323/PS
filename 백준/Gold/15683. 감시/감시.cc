#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

vector<vector<int>> room;
int N, M;

vector<pair<int, int>> cctv;

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M) {
		return true;
	}

	return false;
}

void up(vector<vector<int>> &temp, int y, int x) {
	int nextY = y - 1;
	int nextX = x;

	while (true) {
		if (!inRange(nextY, nextX)) {
			break;
		}

		if (temp[nextY][nextX] == 6) {
			break;
		}

		temp[nextY][nextX] = -1;
		nextY--;
	}
}

void down(vector<vector<int>> &temp, int y, int x) {
	int nextY = y + 1;
	int nextX = x;

	while (true) {
		if (!inRange(nextY, nextX)) {
			break;
		}

		if (temp[nextY][nextX] == 6) {
			break;
		}

		temp[nextY][nextX] = -1;
		nextY++;
	}
}

void left(vector<vector<int>> &temp, int y, int x) {
	int nextY = y;
	int nextX = x - 1;

	while (true) {
		if (!inRange(nextY, nextX)) {
			break;
		}
		if (temp[nextY][nextX] == 6) {
			break;
		}
		temp[nextY][nextX] = -1;
		nextX--;
	}
}

void right(vector<vector<int>> &temp, int y, int x) {
	int nextY = y;
	int nextX = x + 1;

	while (true) {
		if (!inRange(nextY, nextX)) {
			break;
		}
		if (temp[nextY][nextX] == 6) {
			break;
		}
		temp[nextY][nextX] = -1;
		nextX++;
	}
}

void one(vector<vector<int>>& temp, int y, int x, int direction) {
	temp[y][x] = -1;

	switch (direction) {
	case UP:
		up(temp, y, x);
		break;
	case DOWN:
		down(temp, y, x);
		break;
	case LEFT:
		left(temp, y, x);
		break;
	case RIGHT:
		right(temp, y, x);
		break;
	}
}

void two(vector<vector<int>> &temp, int y, int x, int direction) {
	temp[y][x] = -1;
	
	switch (direction) {
	case UP:
		up(temp, y, x);
		down(temp, y, x);
		break;
	case RIGHT:
		left(temp, y, x);
		right(temp, y, x);
		break;
	}
}

void three(vector<vector<int>> &temp, int y, int x, int direction) {
	temp[y][x] = -1;

	switch (direction) {
	case UP:
		up(temp, y, x);
		right(temp, y, x);
		break;
	case DOWN:
		down(temp, y, x);
		left(temp, y, x);
		break;
	case LEFT:
		left(temp, y, x);
		up(temp, y, x);
		break;
	case RIGHT:
		right(temp, y, x);
		down(temp, y, x);
		break;
	}
}

void four(vector<vector<int>> &temp, int y, int x, int direction) {
	temp[y][x] = -1;

	switch (direction) {
	case UP:
		up(temp, y, x);
		left(temp, y, x);
		right(temp, y, x);
		break;
	case DOWN:
		down(temp, y, x);
		left(temp, y, x);
		right(temp, y, x);
		break;
	case LEFT:
		left(temp, y, x);
		up(temp, y, x);
		down(temp, y, x);
		break;
	case RIGHT:
		right(temp, y, x);
		up(temp, y, x);
		down(temp, y, x);
		break;
	}
}

void five(vector<vector<int>> &temp, int y, int x, int direction) {
	temp[y][x] = -1;

	up(temp, y, x);
	down(temp, y, x);
	left(temp, y, x);
	right(temp, y, x);
}

int calculate(vector<int> &directions) {
	vector<vector<int>> temp = room;

	int size = cctv.size();
	for (int i = 0; i < size; i++) {
		int direction = directions[i];
		pair<int, int> cctvIndex = cctv[i];
		int num = room[cctvIndex.first][cctvIndex.second];

		switch (num) {
		case 1:
			one(temp, cctvIndex.first, cctvIndex.second, direction);
			break;
		case 2:
			two(temp, cctvIndex.first, cctvIndex.second, direction);
			break;
		case 3:
			three(temp, cctvIndex.first, cctvIndex.second, direction);
			break;
		case 4:
			four(temp, cctvIndex.first, cctvIndex.second, direction);
			break;
		case 5:
			five(temp, cctvIndex.first, cctvIndex.second, direction);
			break;
		}
	}

	int result = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (temp[y][x] == 0) {
				result++;
			}
		}
	}
	return result;
}

int pick(vector<int>& directions, int index) {
	if (index == cctv.size()) {
		return calculate(directions);
	}

	pair<int, int> cctvIndex = cctv[index];
	int num = room[cctvIndex.first][cctvIndex.second];

	int result = 100;

	if (num == 2) {
		for (int i = 0; i < 2; i++) {
			directions.push_back(i);
			result = min(result, pick(directions, index + 1));
			directions.pop_back();
		}
	} else if (num == 5) {
		directions.push_back(UP);
		result = min(result, pick(directions, index + 1));
		directions.pop_back();
	} else {
		for (int i = 0; i < 4; i++) {
			directions.push_back(i);
			result = min(result, pick(directions, index + 1));
			directions.pop_back();
		}
	}

	return result;
}

bool isTv(int num) {
	if (1 <= num && num <= 5) {
		return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	room = vector<vector<int>>(N, vector<int>(M));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> room[y][x];

			if (isTv(room[y][x])) {
				cctv.push_back({ y, x });
			}
		}
	}

	vector<int> directions;
	int answer = pick(directions, 0);

	cout << answer << '\n';

	return 0;
}