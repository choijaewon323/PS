#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
int maze[101][101];
int dist[101][101];
int bfs(int m, int n) {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	int dy[] = { -1, 0, 0, 1 };
	int dx[] = { 0, -1, 1, 0 };
	dist[1][1] = 0;
	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = present.first + dy[i];
			int x = present.second + dx[i];
			if (present.first == n && present.second == m) {
				continue;
			}
			if (y >= 1 && y <= n && x >= 1 && x <= m) {
				if (maze[y][x] == 1 && (dist[y][x] == -1 || dist[y][x] > dist[present.first][present.second] + 1)) {
					q.push(make_pair(y, x));
					dist[y][x] = dist[present.first][present.second] + 1;
				}
				else if (maze[y][x] == 0 && (dist[y][x] == -1 || dist[y][x] > dist[present.first][present.second])) {
					q.push(make_pair(y, x));
					dist[y][x] = dist[present.first][present.second];
				}
			}
		}
	}
	return dist[n][m];
}
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			maze[i][j + 1] = temp[j] - '0';
		}
	}
	cout << bfs(m, n) << '\n';
	return 0;
}