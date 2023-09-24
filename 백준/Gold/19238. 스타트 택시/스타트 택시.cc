#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

/*
	M명의 승객을 태우는 것이 목표
	NxN 격자, 각 칸은 비어있거나 벽이 있음

	택시가 빈칸에 있을 때, 상하좌우 인접 빈칸 중 하나로 이동 가능

	특정 위치로 이동할 때 항상 최단경로로만 이동함

	여러 승객이 같이 탑승하는 경우는 없음

	태울 승객을 고를 때 최단거리인 승객을 고름

	그런 승객이 여러명이면 행 번호가 가장작은, 그것도 여러명이면 열 번호가 작은

	연료는 한칸 이동할 때마다 1씩 소모, 성공적으로 도착하면 소모한 연료ㅡ의 두배 충전

	승객을 목적지로 이동시킨 동시에 연료가 바닥나는건 실패하지 않은것
*/

struct passenger {
	int startY;
	int startX;
	int endY;
	int endX;
};

int N, M;
long long fuel;
int matrix[21][21];
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
vector<passenger> pass;
vector<vector<int>> dist;

bool inRange(int y, int x) {
	if (1 <= y && y <= N && 1 <= x && x <= N) {
		return true;
	}
	return false;
}

void findPassenger(int startY, int startX) {
	dist = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	queue<pair<int, int>> q;

	q.push({ startY, startX });
	dist[startY][startX] = 1;

	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = present.first + dy[i];
			int nx = present.second + dx[i];

			if (inRange(ny, nx) && dist[ny][nx] == 0 && matrix[ny][nx] != 1) {
				dist[ny][nx] = dist[present.first][present.second] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int movePassenger(int startY, int startX, int endY, int endX) {
	vector<vector<int>> visited(N + 1, vector<int>(N + 1, 0));
	queue<pair<int, int>> q;

	q.push({ startY, startX });
	visited[startY][startX] = 1;

	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();

		if (present.first == endY && present.second == endX) {
			return visited[present.first][present.second] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int ny = present.first + dy[i];
			int nx = present.second + dx[i];

			if (inRange(ny, nx) && visited[ny][nx] == 0 && matrix[ny][nx] != 1) {
				visited[ny][nx] = visited[present.first][present.second] + 1;
				q.push({ ny, nx });
			}
		}
	}

	return -1;
}

bool compare(passenger &a, passenger &b) {
	if (a.startY == b.startY) {
		return a.startX < b.startX;
	}
	return a.startY < b.startY;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> fuel;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> matrix[y][x];
		}
	}

	int startY, startX;

	cin >> startY >> startX;

	for (int i = 1; i <= M; i++) {
		int sy, sx, ey, ex;

		cin >> sy >> sx >> ey >> ex;

		pass.push_back({ sy, sx, ey, ex });
	}

	sort(pass.begin(), pass.end(), compare);

	for (int i = 0; i < M; i++) {
		// 1. move to passenger
		findPassenger(startY, startX);

		passenger result = { -1, -1, -1, -1 };
		int index = -1;
		int tempDist = 1000000;

		for (int i = 0; i < pass.size(); i++) {
			passenger temp = pass[i];
			int distance = dist[temp.startY][temp.startX];

			if (distance > 0) {
				if (tempDist > distance) {
					tempDist = distance;
					result = temp;
					index = i;
				}
			}
		}

		tempDist--;

		if (index == -1) {
			cout << -1 << '\n';
			return 0;
		}

		pass.erase(pass.begin() + index);

		if (fuel - tempDist < 0) {
			cout << -1 << '\n';
			return 0;
		}
		fuel -= tempDist;

		startY = result.startY;
		startX = result.startX;
		int endY = result.endY;
		int endX = result.endX;

		// 2. move to destination
		tempDist = movePassenger(startY, startX, endY, endX);

		if (tempDist == -1) {
			cout << -1 << '\n';
			return 0;
		}

		if (fuel - tempDist < 0) {
			cout << -1 << '\n';
			return 0;
		}

		fuel += tempDist;
		startY = endY;
		startX = endX;
	}

	cout << fuel << '\n';

	return 0;
}