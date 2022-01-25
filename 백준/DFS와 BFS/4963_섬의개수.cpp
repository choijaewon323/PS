#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int w, h;
int map[51][51];
bool isChecked[51][51];
void bfs(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push(make_pair(startY, startX));
	isChecked[startY][startX] = true;
	int dy[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
	int dx[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };
	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int y = present.first + dy[i];
			int x = present.second + dx[i];
			if (y >= 1 && y <= h && x >= 1 && x <= w) {
				if (!isChecked[y][x] && map[y][x] == 1) {
					isChecked[y][x] = true;
					q.push(make_pair(y, x));
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				isChecked[i][j] = false;
				cin >> map[i][j];
			}
		}
		int result = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (!isChecked[i][j] && map[i][j] == 1) {
					bfs(i, j);
					result++;
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}