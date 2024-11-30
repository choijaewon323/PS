#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500

int input[MAX][MAX];
int N, M;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int dp[MAX][MAX];

/*
	dp[y][x] : (y, x)에서 출발해서 제일 오른쪽 아래까지 내리막길로 가는 경로의 수
*/

bool inRange(int y, int x) {
	return (0 <= y && y < N && 0 <= x && x < M);
}

int solve(int y, int x) {
	if (y == N - 1 && x == M - 1) {
		return 1;
	}

	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	int result = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (inRange(ny, nx) && input[ny][nx] < input[y][x]) {
			result += solve(ny, nx);
		}
	}

	return dp[y][x] = result;
}

void init() {
	for (int y = 0; y < MAX; y++) {
		for (int x = 0; x < MAX; x++) {
			dp[y][x] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> input[y][x];
		}
	}

	init();

	cout << solve(0, 0) << '\n';

	return 0;
}