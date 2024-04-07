#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20
#define EMTPY 0
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#define CHECK 5

struct Warm {
	int y;
	int x;
	int direction;
};

int R, C, K;
vector<pair<int, int>> checks;
vector<Warm> warms;
vector<vector<int>> temperature;
bool isWall[MAX + 1][MAX + 1][MAX + 1][MAX + 1];

bool isWarm(int num) {
	if (1 <= num && num <= 4) {
		return true;
	}
	return false;
}

bool isCheck(int num) {
	if (num == 5) {
		return true;
	}
	return false;
}

void input() {
	cin >> R >> C >> K;
	
	temperature = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			int temp;
			cin >> temp;
			if (isWarm(temp)) {
				warms.push_back({ y, x, temp - 1 });
			} else if (isCheck(temp)) {
				checks.push_back({ y, x });
			}
		}
	}
	int W;
	cin >> W;
	for (int i = 0; i < W; i++) {
		int y, x, t;

		cin >> y >> x >> t;
		if (t == 0) {
			isWall[y][x][y - 1][x] = true;
			isWall[y - 1][x][y][x] = true;
		} else {
			isWall[y][x][y][x + 1] = true;
			isWall[y][x + 1][y][x] = true;
		}
	}
}

bool inRange(int y, int x) {
	if (1 <= y && y <= R && 1 <= x && x <= C) {
		return true;
	}
	return false;
}

pair<int, int> startPos(int y, int x, int direction) {
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

pair<int, int> firstCheck(int y, int x, int direction) {
	int ny, nx;
	
	switch (direction) {
	case RIGHT:
		ny = y - 1;
		nx = x + 1;
		if (inRange(ny, nx) && !isWall[y][x][ny][x] && !isWall[ny][x][ny][nx]) {
			return { ny, nx };
		}
		break;
	case LEFT:
		ny = y - 1;
		nx = x - 1;
		if (inRange(ny, nx) && !isWall[y][x][ny][x] && !isWall[ny][x][ny][nx]) {
			return { ny, nx };
		}
		break;
	case UP:
		ny = y - 1;
		nx = x - 1;
		if (inRange(ny, nx) && !isWall[y][x][y][nx] && !isWall[y][nx][ny][nx]) {
			return { ny, nx };
		}
		break;
	case DOWN:
		ny = y + 1;
		nx = x - 1;
		if (inRange(ny, nx) && !isWall[y][x][y][nx] && !isWall[y][nx][ny][nx]) {
			return { ny, nx };
		}
		break;
	}
	return { -1, -1 };
}

pair<int, int> secondCheck(int y, int x, int direction) {
	int ny, nx;

	switch (direction) {
	case RIGHT:
		ny = y;
		nx = x + 1;
		if (inRange(ny, nx) && !isWall[y][x][y][nx]) {
			return { ny, nx };
		}
		break;
	case LEFT:
		ny = y;
		nx = x - 1;
		if (inRange(ny, nx) && !isWall[y][x][y][nx]) {
			return { ny, nx };
		}
		break;
	case UP:
		ny = y - 1;
		nx = x;
		if (inRange(ny, nx) && !isWall[y][x][ny][x]) {
			return { ny, nx };
		}
		break;
	case DOWN:
		ny = y + 1;
		nx = x;
		if (inRange(ny, nx) && !isWall[y][x][ny][x]) {
			return { ny, nx };
		}
		break;
	}
	return { -1, -1 };
}

pair<int, int> thirdCheck(int y, int x, int direction) {
	int ny, nx;

	switch (direction) {
	case RIGHT:
		ny = y + 1;
		nx = x + 1;
		if (inRange(ny, nx) && !isWall[y][x][ny][x] && !isWall[ny][x][ny][nx]) {
			return { ny, nx };
		}
		break;
	case LEFT:
		ny = y + 1;
		nx = x - 1;
		if (inRange(ny, nx) && !isWall[y][x][ny][x] && !isWall[ny][x][ny][nx]) {
			return { ny, nx };
		}
		break;
	case UP:
		ny = y - 1;
		nx = x + 1;
		if (inRange(ny, nx) && !isWall[y][x][y][nx] && !isWall[y][nx][ny][nx]) {
			return { ny, nx };
		}
		break;
	case DOWN:
		ny = y + 1;
		nx = x + 1;
		if (inRange(ny, nx) && !isWall[y][x][y][nx] && !isWall[y][nx][ny][nx]) {
			return { ny, nx };
		}
		break;
	}
	return { -1, -1 };
}

void print();

void bfs(int startY, int startX, int direction) {
	vector<vector<int>> visited(R + 1, vector<int>(C + 1, -1));

	queue<pair<int, int>> q;
	visited[startY][startX] = 5;
	q.push({ startY, startX });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (visited[y][x] == 1) {
			continue;
		}

		int ny, nx;

		pair<int, int> first = firstCheck(y, x, direction);
		ny = first.first;
		nx = first.second;
		if (ny != -1 && visited[ny][nx] == -1) {
			visited[ny][nx] = visited[y][x] - 1;
			q.push({ ny, nx });
		}

		pair<int, int> second = secondCheck(y, x, direction);
		ny = second.first;
		nx = second.second;
		if (ny != -1 && visited[ny][nx] == -1) {
			visited[ny][nx] = visited[y][x] - 1;
			q.push({ ny, nx });
		}

		pair<int, int> third = thirdCheck(y, x, direction);
		ny = third.first;
		nx = third.second;
		if (ny != -1 && visited[ny][nx] == -1) {
			visited[ny][nx] = visited[y][x] - 1;
			q.push({ ny, nx });
		}
	}
	
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (visited[y][x] == -1) {
				continue;
			}

			temperature[y][x] += visited[y][x];
		}
	}
}

void warmFunc() {
	for (Warm &warm : warms) {
		int y = warm.y;
		int x = warm.x;
		int direction = warm.direction;

		pair<int, int> start = startPos(y, x, direction);
		if (inRange(start.first, start.second) && !isWall[y][x][start.first][start.second]) {
			bfs(start.first, start.second, direction);
		}
	}
}

int dy[] = { 0, 1 };
int dx[] = { 1, 0 };

int absolute(int n) {
	if (n < 0) {
		return -n;
	}
	return n;
}

void regulate() {
	vector<vector<int>> result = temperature;

	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			for (int i = 0; i < 2; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (inRange(ny, nx) && !isWall[y][x][ny][nx]) {
					int dist = temperature[y][x] - temperature[ny][nx];
					int absDist = absolute(dist);
					absDist /= 4;

					if (dist > 0) {	// present down, next up
						result[y][x] -= absDist;
						result[ny][nx] += absDist;
					} else if (dist < 0) { // present up, next down
						result[y][x] += absDist;
						result[ny][nx] -= absDist;
					}
				}
			}
		}
	}

	temperature = result;
}

void decreaseEdge() {
	for (int x = 2; x < C; x++) {
		if (temperature[1][x] >= 1) {
			temperature[1][x]--;
		}
		if (temperature[R][x] >= 1) {
			temperature[R][x]--;
		}
	}
	for (int y = 1; y <= R; y++) {
		if (temperature[y][1] >= 1) {
			temperature[y][1]--;
		}
		if (temperature[y][C] >= 1) {
			temperature[y][C]--;
		}
	}
}

bool isEnd() {
	for (pair<int, int> &c : checks) {
		if (temperature[c.first][c.second] < K) {
			return false;
		}
	}
	return true;
}

void print() {
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			cout << temperature[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int solve() {
	for (int result = 1; result <= 100; result++) {
		// some action
		warmFunc();
		regulate();
		decreaseEdge();
		if (isEnd()) {
			return result;
		}
	}

	return 101;
}

void test() {
	R = 3;
	C = 3;
	temperature = vector<vector<int>>(4, vector<int>(4, 0));
	temperature[2][2] = 46;
	temperature[3][2] = 2;

	regulate();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}