#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define MAX 16
#define MIN -10000000

int N;
bool matrix[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1][3];

vector<pair<int, int>> check[3][3];
vector<int> nextPos[3];

void init() {
	check[0][0] = { {0, 1} };
	check[0][1] = { {0,1},{1,0},{1,1} };
	nextPos[0] = { 0,1 };

	check[1][0] = { {0,1} };
	check[1][1] = { {1,0} };
	check[1][2] = { {0,1},{1,0},{1,1} };
	nextPos[1] = { 0,2,1 };

	check[2][0] = { {1,0} };
	check[2][1] = { {0,1},{1,0},{1,1} };
	nextPos[2] = { 2,1 };

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			for (int i = 0; i < 3; i++) {
				dp[y][x][i] = -1;
			}
		}
	}
}

bool inRange(int y, int x) {
	if (1 <= y && y <= N && 1 <= x && x <= N) {
		return true;
	}
	return false;
}

int solve(int y, int x, int state) {
	if (y == N && x == N) {
		return 1;
	}

	if (dp[y][x][state] != -1) {
		return dp[y][x][state];
	}

	int answer = 0;

	for (int i = 0; i < 3; i++) {
		if ((state == 0 || state == 2) && i == 2) {
			continue;
		}

		bool flag = true;

		for (pair<int, int> &p : check[state][i]) {
			int ny = y + p.first;
			int nx = x + p.second;

			if (!inRange(ny, nx)) {
				flag = false;
				break;
			}

			if (matrix[ny][nx]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			int nextState = nextPos[state][i];
			int ny, nx;

			if (nextState == 0) {
				ny = y;
				nx = x + 1;
			}
			else if (nextState == 1) {
				ny = y + 1;
				nx = x + 1;
			}
			else {
				ny = y + 1;
				nx = x;
			}

			answer += solve(ny, nx, nextState);
		}
	}

	return dp[y][x][state] = answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> matrix[y][x];
		}
	}

	init();

	cout << solve(1, 2, 0) << '\n';

	return 0;
}