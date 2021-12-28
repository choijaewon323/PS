#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int box[101][101][101];
int distances[101][101][101];

typedef struct loc {
	int z;
	int y;
	int x;
} location;

void bfs(int m, int n, int h, vector<location>& ripped) {
	queue<location> q;

	int dz[] = { -1, 1, 0, 0, 0, 0 };
	int dy[] = { 0, 0, -1, 1, 0, 0 };
	int dx[] = { 0, 0, 0, 0, -1, 1 };

	for (auto i : ripped) {
		distances[i.z][i.y][i.x] = 1;
		q.push(i);
	}

	while (!q.empty()) {
		location present = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int z = present.z + dz[i];
			int y = present.y + dy[i];
			int x = present.x + dx[i];

			if ((z >= 0 && z < h) && (y >= 0 && y < n) && (x >= 0 && x < m)) {
				if (box[z][y][x] == 0) {
					if (!distances[z][y][x]) {
						location loc = { z,y,x };

						box[z][y][x] = 1;
						distances[z][y][x] = distances[present.z][present.y][present.x] + 1;
						q.push(loc);
					}
				}
			}
		}
	}

}

int main() {
	int m, n, h;
	int numOfUnrip = 0;
	vector<location> ripped;
	cin >> m >> n >> h;

	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> box[z][y][x];
				
				if (box[z][y][x] == 1) {
					location temp;
					temp.z = z;
					temp.y = y;
					temp.x = x;

					ripped.push_back(temp);
				}
				if (box[z][y][x] == 0) {
					numOfUnrip++;
				}
			}
		}
	}

	if (!ripped.empty() && !numOfUnrip) {
		cout << 0 << '\n';
		
		return 0;
	}

	bfs(m, n, h, ripped);

	int result = -1;

	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (box[z][y][x] == 0) {
					cout << -1 << '\n';
					
					return 0;
				}

				if (result < distances[z][y][x]) {
					result = distances[z][y][x];
				}
			}
		}
	}

	cout << result - 1 << '\n';

	return 0;
}