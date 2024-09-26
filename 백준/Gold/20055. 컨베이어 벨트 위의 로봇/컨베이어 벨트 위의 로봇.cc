#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> A;
vector<bool> robots;

bool isEnd() {
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (A[i] == 0) {
			cnt++;
		}
	}

	if (cnt >= K) {
		return true;
	}
	return false;
}

void rotate() {
	vector<int> next(2 * N);
	vector<bool> nextRobot(2 * N);

	for (int i = 0; i < 2 * N - 1; i++) {
		next[i + 1] = A[i];
		nextRobot[i + 1] = robots[i];
	}
	
	next[0] = A[2 * N - 1];
	nextRobot[0] = robots[2 * N - 1];
	
	if (nextRobot[N - 1]) {
		nextRobot[N - 1] = false;
	}
	
	A = next;
	robots = nextRobot;
}

void moveRobot() {
	for (int i = N - 2; i >= 0; i--) {
		if (robots[i] && !robots[i + 1] && A[i + 1] > 0) {
			robots[i] = false;
			robots[i + 1] = true;
			A[i + 1]--;
		}
	}

	if (robots[N - 1]) {
		robots[N - 1] = false;
	}
}

void upRobot() {
	if (!robots[0] && A[0] > 0) {
		robots[0] = true;
		A[0]--;
	}
}

int solve() {
	int step = 1;
	while (true) {
		// 1. rotate
		rotate();

		// 2. robot move
		moveRobot();

		// 3. robot up
		upRobot();

		// 4. check end
		if (isEnd()) {
			return step;
		}

		// after
		step++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	A = vector<int>(2 * N);
	robots = vector<bool>(2 * N, false);
	for (int i = 0; i < 2 * N; i++) {
		cin >> A[i];
	}

	cout << solve() << '\n';

	return 0;
}