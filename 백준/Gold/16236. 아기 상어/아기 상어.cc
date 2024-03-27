#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20
#define INF 1000000000

int N;
int matrix[MAX][MAX];
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

struct Next {
	pair<int, int> pos;
	int dist;
};

bool isBlank(int a) {
	if (a == 0) {
		return true;
	}

	return false;
}

bool isFish(int a) {
	if (1 <= a && a <= 6) {
		return true;
	}

	return false;
}

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N) {
		return true;
	}

	return false;
}

int bfs(int startY, int startX, int endY, int endX, int shark) {
	vector<vector<int>> dist(N, vector<int>(N, -1));
	queue<pair<int, int>> q;

	dist[startY][startX] = 0;
	q.push({ startY, startX });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == endY && x == endX) {
			return dist[y][x];
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!inRange(ny, nx)) {
				continue;
			}

			if (isBlank(matrix[ny][nx]) && dist[ny][nx] == -1) {
				dist[ny][nx] = dist[y][x] + 1;
				q.push({ ny, nx });
			}

			if (isFish(matrix[ny][nx]) && matrix[ny][nx] <= shark && dist[ny][nx] == -1) {
				dist[ny][nx] = dist[y][x] + 1;
				q.push({ ny ,nx });
			}
		}
	}

	return -1;
}

Next nextFish(int startY, int startX, int shark) {
	pair<int, int> result = { -1, -1 };
	int resultDist = INF;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (isFish(matrix[y][x]) && matrix[y][x] < shark) {
				int dist = bfs(startY, startX, y, x, shark);

				if (dist == -1) {
					continue;
				}

				if (resultDist > dist) {
					resultDist = dist;
					result = { y, x };
				}
			}
		}
	}
	
	return { result, resultDist };
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int babyY, babyX;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int temp;

			cin >> temp;

			if (temp == 9) {
				babyY = y;
				babyX = x;
			} else {
				matrix[y][x] = temp;
			}
		}
	}
	

	int babySize = 2;
	int eat = 0;
	int second = 0;

	while (true) {
		Next next = nextFish(babyY, babyX, babySize);
		
		if (next.dist == INF) {
			cout << second << '\n';
			return 0;
		}

		babyY = next.pos.first;
		babyX = next.pos.second;
		matrix[babyY][babyX] = 0;
		
		second += next.dist;
		eat++;
		
		if (eat == babySize) {
			babySize++;
			eat = 0;
		}
	}

	return 0;
}