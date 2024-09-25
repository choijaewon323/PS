#include <iostream>
#include <vector>
using namespace std;

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

#define MAX 499

int A[MAX][MAX];
int N;

struct Node {
	int y;
	int x;
};

struct WindNode {
	int dy;
	int dx;
	int percent;
};

vector<WindNode> wind[4] = {
	{	// left
		{-1, 1, 1}, {1, 1, 1},
		{-2, 0, 2}, {2, 0, 2},
		{-1, 0, 7}, {1, 0, 7},
		{-1, -1, 10}, {1, -1, 10},
		{0, -2, 5}
	},
	{	// down
		{-1, -1, 1}, {-1, 1, 1},
		{0, -2, 2}, {0, 2, 2},
		{0, -1, 7}, {0, 1, 7},
		{1, -1, 10}, {1, 1, 10},
		{2, 0, 5}
	},
	{	// right
		{-1, -1, 1}, {1, -1, 1},
		{-2, 0, 2}, {2, 0, 2},
		{-1, 0, 7}, {1, 0, 7},
		{-1, 1, 10}, {1, 1, 10},
		{0, 2, 5}
	},
	{	// up
		{1, -1, 1}, {1, 1, 1},
		{0, -2, 2}, {0, 2, 2},
		{0, -1, 7}, {0, 1, 7},
		{-1, -1, 10}, {-1, 1, 10},
		{-2, 0, 5}
	}
};

bool inRange(int y, int x) {
	return (0 <= y && y < N && 0 <= x && x < N);
}

int calculate(int y, int x, int direction) {
	int out = 0;
	int present = A[y][x];
	int rest = present;
	A[y][x] = 0;

	for (WindNode &windNode : wind[direction]) {
		int ny = y + windNode.dy;
		int nx = x + windNode.dx;
		int percent = windNode.percent;

		int temp = present * percent / 100;
		
		if (!inRange(ny, nx)) {
			out += temp;
		} else {
			A[ny][nx] += temp;
		}
		rest -= temp;
	}

	int ay, ax;

	switch (direction) {
	case LEFT:
		ay = y;
		ax = x - 1;
		
		if (!inRange(ay, ax)) {
			out += rest;
			
		} else {
			A[ay][ax] += rest;
		}
		break;
	case DOWN:
		ay = y + 1;
		ax = x;

		if (!inRange(ay, ax)) {
			out += rest;

		} else {
			A[ay][ax] += rest;
		}
		break;
	case RIGHT:
		ay = y;
		ax = x + 1;

		if (!inRange(ay, ax)) {
			out += rest;

		} else {
			A[ay][ax] += rest;
		}
		break;
	case UP:
		ay = y - 1;
		ax = x;

		if (!inRange(ay, ax)) {
			out += rest;

		} else {
			A[ay][ax] += rest;
		}
		break;
	}

	return out;
}

int nextDirection(int direction) {
	return (direction + 1) % 4;
}

Node nextPos(int y, int x, int direction) {
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

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << A[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

vector<int> makeCounts() {
	vector<int> counts;

	for (int number = 1; number <= N - 1; number++) {
		counts.push_back(number);
		counts.push_back(number);
	}
	counts.push_back(N - 1);
	return counts;
}

int solve() {
	vector<int> counts = makeCounts();

	int y = N / 2;
	int x = N / 2;
	int direction = LEFT;
	
	int answer = 0;

	for (int count : counts) {
		for (int i = 0; i < count; i++) {
			Node next = nextPos(y, x, direction);

			// do something
			answer += calculate(next.y, next.x, direction);
		
			// after
			y = next.y;
			x = next.x;
		}

		direction = nextDirection(direction);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> A[y][x];
		}
	}

	cout << solve() << '\n';

	return 0;
}