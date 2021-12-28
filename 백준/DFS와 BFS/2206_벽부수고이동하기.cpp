#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool matrix[1001][1001];
int distances[1001][1001][2];

typedef struct loc {
	int y;
	int x;
	bool breakable;
} location;

void bfs(int n, int m) {
	queue<location> q;
	
	distances[1][1][1] = 1;
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	location start = { 1, 1, true };
	q.push(start);

	while (!q.empty()) {
		location present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int y = present.y + dy[i];
			int x = present.x + dx[i];

			if (y == n && x == m) {
				if (distances[y][x][present.breakable] > distances[present.y][present.x][present.breakable] + 1)
				distances[y][x][present.breakable] = distances[present.y][present.x][present.breakable] + 1;
			}

			if ((y >= 1 && y <= n) && (x >= 1 && x <= m)) {
				if (!matrix[y][x] && present.breakable) {
					if (distances[y][x][false] == 0) {
						distances[y][x][false] = distances[present.y][present.x][present.breakable] + 1;
						location temp = { y, x, false };
						q.push(temp);
					}
				}
				else if (matrix[y][x]) {
					if (distances[y][x][present.breakable] == 0) {
						distances[y][x][present.breakable] = distances[present.y][present.x][present.breakable] + 1;
						location temp = { y, x, present.breakable };
						q.push(temp);
					}
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int y = 1; y <= n; y++) {
		string temp;
		cin >> temp;

		for (int x = 0; x < temp.size(); x++) {
			if (temp[x] == '0') {
				matrix[y][x + 1] = true;
			}
		}
	}

	bfs(n, m);

	if (distances[n][m][true] == 0 && distances[n][m][false] == 0) {
		cout << -1 << '\n';
	}
	else {
		if (distances[n][m][true] == 0) {
			cout << distances[n][m][false] << '\n';
		}
		else if (distances[n][m][false] == 0) {
			cout << distances[n][m][true] << '\n';
		}
		else {
			cout << min(distances[n][m][true], distances[n][m][false]) << '\n';
		}
	}

	return 0;
}