#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define MAX 1000
#define INF 1000000000
#define NOT_DESTROY 0
#define DESTROY 1

int N, M;
int matrix[MAX + 1][MAX + 1];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool inRange(int y, int x) {
	if (1 <= y && y <= N && 1 <= x && x <= M) {
		return true;
	}

	return false;
}

int answer = INF;
int dist[MAX + 1][MAX + 1][2];

struct Node {
	int y;
	int x;
	int destroy;
};

int bfs(int startY, int startX) {
	dist[startY][startX][NOT_DESTROY] = 1;
	queue<Node> q;
	q.push({ startY, startX, NOT_DESTROY });

	while (!q.empty()) {
		Node present = q.front();
		q.pop();

		int y = present.y;
		int x = present.x;
		int destroy = present.destroy;
		
		if (y == N && x == M) {
			return dist[y][x][destroy];
		}

		for (int i = 0; i < 4; i++) {
			int ny = present.y + dy[i];
			int nx = present.x + dx[i];

			if (!inRange(ny, nx)) {
				continue;
			}

			if (destroy == NOT_DESTROY) {
				if (matrix[ny][nx] == 0 && dist[ny][nx][destroy] > dist[y][x][destroy] + 1) {
					dist[ny][nx][destroy] = dist[y][x][destroy] + 1;
					q.push({ ny, nx, destroy });
				} else if (matrix[ny][nx] == 1 && dist[ny][nx][DESTROY] > dist[y][x][destroy] + 1) {
					dist[ny][nx][DESTROY] = dist[y][x][destroy] + 1;
					q.push({ ny,nx,DESTROY });
				}
			} else if (destroy == DESTROY) {
				if (matrix[ny][nx] == 0 && dist[ny][nx][destroy] > dist[y][x][destroy] + 1) {
					dist[ny][nx][destroy] = dist[y][x][destroy] + 1;
					q.push({ ny,nx,destroy });
				}
			}
		}
	}
	return -1;
}

void solve(int y, int x, int destroy) {
	if (y == N && x == M) {
		answer = min(answer, dist[y][x][destroy]);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!inRange(ny, nx)) {
			continue;
		}
		
		if (destroy == NOT_DESTROY) {
			if (matrix[ny][nx] == 0 && dist[ny][nx][destroy] > dist[y][x][destroy] + 1) {
				dist[ny][nx][destroy] = dist[y][x][destroy] + 1;
				solve(ny, nx, destroy);
			} else if (matrix[ny][nx] == 1 && dist[ny][nx][DESTROY] > dist[y][x][destroy] + 1) {
				dist[ny][nx][DESTROY] = dist[y][x][destroy] + 1;
				solve(ny, nx, DESTROY);
			}
		} else if (destroy == DESTROY) {
			if (matrix[ny][nx] == 0 && dist[ny][nx][destroy] > dist[y][x][destroy] + 1) {
				dist[ny][nx][destroy] = dist[y][x][destroy] + 1;
				solve(ny, nx, destroy);
			}
		}
	}
}

void init() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			for (int i = 0; i < 2; i++) {
				dist[y][x][i] = INF;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	init();

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			char c;
			cin >> c;
			matrix[y][x] = c - '0';
		}
	}

	int result = bfs(1, 1);
	
	cout << result << '\n';
	
	return 0;
}