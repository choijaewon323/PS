#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n;
char grid[101][101];
bool isChecked[101][101];
void bfs(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push(make_pair(startY, startX));
	isChecked[startY][startX] = true;
	char color = grid[startY][startX];
	int dy[4] = { -1, 0, 0, 1 };
	int dx[4] = { 0, -1, 1, 0 };
	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = present.first + dy[i];
			int x = present.second + dx[i];
			if (y >= 1 && y <= n && x >= 1 && x <= n) {
				if (!isChecked[y][x] && color == grid[y][x]) {
					isChecked[y][x] = true;
					q.push(make_pair(y, x));
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}
	int normal = 0;
	int abnormal = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!isChecked[i][j]) {
				bfs(i, j);
				normal++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			isChecked[i][j] = false;
			if (grid[i][j] == 'G') {
				grid[i][j] = 'R';
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!isChecked[i][j]) {
				bfs(i, j);
				abnormal++;
			}
		}
	}
	cout << normal << " " << abnormal << '\n';
	return 0;
}