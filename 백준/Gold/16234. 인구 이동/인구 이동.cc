#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

/*
	N * N 크기의 땅이 있다.
	땅은 1 * 1개의 칸으로 나누어졌다.

	각 땅에는 나라가 하나씩 존재, r행 c열에 있는 나라에는
	A[r][c] 명이 살고 있다.

	인구 이동은 하루 동안 다음과 같이 진행, 더 이상 안될때까지 지속
	1. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면,
	두 나라가 공유하는 국경선을 하루동안 연다.
	2. 모든 국경선이 열렸다면, 인구 이동을 시작
	3. 국경선이 열려있어 인접한 칸만을 통해 이동 가능하면 연합임
	4. 연합을 이루고 있는 각 칸의 인구수는 연합의 인구수 / 연합을 이루고 있는 칸의 개수
	-> 소수점은 버림
	5. 연합을 해체하고, 모든 국경선을 닫음
*/
#define MAX 50

int N, L, R;
int world[MAX][MAX];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N) {
		return true;
	}

	return false;
}

int absolute(int a) {
	if (a < 0) {
		return -a;
	}

	return a;
}

bool isPossible(int ny, int nx, int presentY, int presentX) {
	int dist = absolute(world[ny][nx] - world[presentY][presentX]);

	if (L <= dist && dist <= R) {
		return true;
	}

	return false;
}

vector<pair<int, int>> bfs(int startY, int startX, vector<vector<bool>> &visited) {
	visited[startY][startX] = true;
	queue<pair<int, int>> q;
	vector<pair<int, int>> result;

	result.push_back({ startY, startX });
	q.push({ startY, startX });

	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = present.first + dy[i];
			int nx = present.second + dx[i];

			if (inRange(ny, nx) && !visited[ny][nx] &&
				isPossible(ny, nx, present.first, present.second)) {
				result.push_back({ ny, nx });
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	return result;
}

vector<vector<pair<int, int>>> openDoor() {
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	vector<vector<pair<int, int>>> result;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!visited[y][x]) {
				vector<pair<int, int>> area = bfs(y, x, visited);
				result.push_back(area);
			}
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> L >> R;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> world[y][x];
		}
	}

	for (int day = 0; day <= 2000; day++) {
		vector<vector<pair<int, int>>> open = openDoor();

		if (open.size() == N * N) {
			cout << day << '\n';
			return 0;
		}

		for (vector<pair<int, int>> &area : open) {
			int acc = 0;

			for (pair<int, int> &element : area) {
				int y = element.first;
				int x = element.second;

				acc += world[y][x];
			}

			acc /= area.size();

			for (pair<int, int> &element : area) {
				int y = element.first;
				int x = element.second;

				world[y][x] = acc;
			}
		}
	}

	return 0;
}