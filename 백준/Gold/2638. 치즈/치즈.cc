#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define MAX 100

int N, M;
vector<vector<int>> cheeze;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void input() {
	cin >> N >> M;
	cheeze = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> cheeze[y][x];
		}
	}
}

bool isEnd() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (cheeze[y][x] == 1) {
				return false;
			}
		}
	}
	return true;
}

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M) {
		return true;
	}
	return false;
}

vector<vector<bool>> bfs(int startY, int startX) {
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<pair<int, int>> q;
	visited[startY][startX] = true;
	q.push({ startY, startX });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (inRange(ny, nx) && !visited[ny][nx] && cheeze[ny][nx] == 0) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	return visited;
}

void removeCheeze(vector<vector<bool>>& outer) {
	vector<vector<int>> result = cheeze;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (cheeze[y][x] == 0) {
				continue;
			}

			int airCnt = 0;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (!inRange(ny, nx)) {
					continue;
				}

				if (cheeze[ny][nx] == 1) {
					continue;
				}

				if (cheeze[ny][nx] == 0 && outer[ny][nx]) {
					airCnt++;
				}
			}

			if (airCnt >= 2) {
				result[y][x] = 0;
			}
		}
	}

	cheeze = result;
}

int solve() {
	if (isEnd()) {
		return 0;
	}

	int result = 0;
	while (true) {
		result++;
		// find outer air
		vector<vector<bool>> outerAir = bfs(0, 0);
		removeCheeze(outerAir);

		if (isEnd()) {
			return result;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}