#include <iostream>
using namespace std;
int m, n;
int map[501][501];
int cache[501][501];
int func(int y, int x) {
	if (y == m && x == n) {
		return 1;
	}
	int& ret = cache[y][x];
	if (ret != -1) {
		return ret;
	}
	int result = 0;
	int dy[4] = { -1, 0, 0, 1 };
	int dx[4] = { 0, -1, 1, 0 };
	for (int i = 0; i < 4; i++) {
		int tempY = y + dy[i];
		int tempX = x + dx[i];
		if (tempY >= 1 && tempY <= m && tempX >= 1 && tempX <= n) {
			if (map[tempY][tempX] < map[y][x]) {
				cache[tempY][tempX] = func(tempY, tempX);
				result += cache[tempY][tempX];
			}
		}
	}
	return ret = result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			cache[i][j] = -1;
		}
	}
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cout << func(1, 1) << '\n';
	return 0;
}