#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define MAX 16
#define GARO 0
#define DAEGAK 1
#define SERO 2

int N;
int house[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1][3];

void init() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			for (int i = 0; i < 3; i++) {
				dp[y][x][i] = -1;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> house[y][x];
		}
	}
}

bool inRange(int y, int x) {
	if (1 <= y && y <= N && 1 <= x && x <= N) {
		return true;
	}
	return false;
}

int solve(int y, int x, int direction) {
	if (y == N && x == N) {
		return 1;
	}
	if (dp[y][x][direction] != -1) {
		return dp[y][x][direction];
	}
	int result = 0;
	if (direction == GARO) {
		// garo
		if (inRange(y, x + 1) && house[y][x + 1] == 0) {
			result += solve(y, x + 1, GARO);
		}
		// daegak
		if (inRange(y, x + 1) && inRange(y + 1, x + 1) && inRange(y + 1, x)) {
			if (house[y][x + 1] == 0 && house[y + 1][x + 1] == 0 && house[y + 1][x] == 0) {
				result += solve(y + 1, x + 1, DAEGAK);
			}
		}
		return dp[y][x][direction] = result;
	} else if (direction == SERO) {
		// sero
		if (inRange(y + 1, x) && house[y + 1][x] == 0) {
			result += solve(y + 1, x, SERO);
		}
		// daegak
		if (inRange(y, x + 1) && inRange(y + 1, x + 1) && inRange(y + 1, x)) {
			if (house[y][x + 1] == 0 && house[y + 1][x + 1] == 0 && house[y + 1][x] == 0) {
				result += solve(y + 1, x + 1, DAEGAK);
			}
		}
		return dp[y][x][direction] = result;
	} else {
		// garo
		if (inRange(y, x + 1) && house[y][x + 1] == 0) {
			result += solve(y, x + 1, GARO);
		}
		// daegak
		if (inRange(y, x + 1) && inRange(y + 1, x + 1) && inRange(y + 1, x)) {
			if (house[y][x + 1] == 0 && house[y + 1][x + 1] == 0 && house[y + 1][x] == 0) {
				result += solve(y + 1, x + 1, DAEGAK);
			}
		}
		// sero
		if (inRange(y + 1, x) && house[y + 1][x] == 0) {
			result += solve(y + 1, x, SERO);
		}
		return dp[y][x][direction] = result;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	init();
	cout << solve(1, 2, GARO) << '\n';

	return 0;
}