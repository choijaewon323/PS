#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

/*
	dp[y][x] : (y, x)를 좌상단으로 놨을 때 가장 큰 정사각형의 크기

	dp[y][x] : min(dp[y][x + 1], dp[y + 1][x], dp[y + 1][x + 1]) + 1
*/

#define MAX 1000

int dp[MAX][MAX];
int n, m;
char input[MAX][MAX];

void init() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			dp[y][x] = -1;
		}
	}
}

bool inRange(int y, int x) {
	return (0 <= y && y < n && 0 <= x && x < m);
}

int dy[] = { 0, 1, 1 };
int dx[] = { 1, 0, 1 };

int solve(int y, int x) {
	if (!inRange(y, x)) {
		return 0;
	}

	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	if (input[y][x] == '0') {
		return 0;
	}

	int minRes = 1000001;
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!inRange(ny, nx)) {
			minRes = 0;
			break;
		}
		
		minRes = min(minRes, solve(ny, nx));
	}
	minRes++;

	return dp[y][x] = minRes;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> input[y][x];
		}
	}

	init();

	int result = -1;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			result = max(result, solve(y, x));
		}
	}

	cout << result * result << '\n';

	return 0;
}