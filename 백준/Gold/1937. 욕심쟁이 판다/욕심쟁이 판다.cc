#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define MAX 500

int input[MAX][MAX];
int dp[MAX][MAX];
int n;

void init() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			dp[y][x] = -1;
		}
	}
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool inRange(int y, int x) {
	return (0 <= y && y < n && 0 <= x && x < n);
}

int solve(int y, int x) {
	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	int result = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (inRange(ny, nx) && input[ny][nx] > input[y][x]) {
			result = max(result, solve(ny, nx) + 1);
		}
	}
	
	return dp[y][x] = result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> input[y][x];
		}
	}

	init();

	int answer = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			answer = max(answer, solve(y, x));
		}
	}
	cout << answer + 1 << '\n';

	return 0;
}