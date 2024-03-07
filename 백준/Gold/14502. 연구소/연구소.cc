#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 8

int N, M;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
bool picked[MAX][MAX];
vector<vector<int>> matrix;
vector<pair<int, int>> virus;

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M) {
		return true;
	}
	return false;
}

int bfs(vector<vector<int>> present) {
	queue<pair<int, int>> q;
	
	for (pair<int, int> &v : virus) {
		q.push(v);
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (inRange(ny, nx) && present[ny][nx] == 0) {
				present[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}

	int result = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (present[y][x] == 0) {
				result++;
			}
		}
	}
	return result;
}

int pick(int prevY, int prevX, int cnt) {
	if (cnt == 3) {
		return bfs(matrix);
	}

	int result = 0;
	for (int y = prevY; y < N; y++) {
		if (y == prevY) {
			for (int x = prevX; x < M; x++) {
				if (!picked[y][x] && matrix[y][x] == 0) {
					picked[y][x] = true;
					matrix[y][x] = 1;
					result = max(result,
						pick(y, x, cnt + 1));
					picked[y][x] = false;
					matrix[y][x] = 0;
				}
			}
		} else {
			for (int x = 0; x < M; x++) {
				if (!picked[y][x] && matrix[y][x] == 0) {
					if (!picked[y][x] && matrix[y][x] == 0) {
						picked[y][x] = true;
						matrix[y][x] = 1;
						result = max(result,
							pick(y, x, cnt + 1));
						picked[y][x] = false;
						matrix[y][x] = 0;
					}
				}
			}
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	matrix = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> matrix[y][x];

			if (matrix[y][x] == 2) {
				virus.push_back({ y, x });
			}
		}
	}

	int result = pick(0, 0, 0);

	cout << result << '\n';

	return 0;
}