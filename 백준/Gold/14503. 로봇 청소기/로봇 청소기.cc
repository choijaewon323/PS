#include <iostream>
#include <utility>

using namespace std;

/*
	1. 현재 칸이 청소되지 않은 경우, 현재 칸 청소
	2. 현재 칸 주변 4칸 중 청소되지 않은 빈칸이 없다면
		1. 바라보는 방향 유지한 채로 한칸 후진할 수 있다면 한칸 후진 후 1번 돌아감
		2. 바라보는 방향 뒤쪽이 벽이라 후진 불가능하면 작동 멈춤
	3. 현재 칸 주변 4칸 중 청소되지 않은 빈칸이 있다면
		1. 반시계 방향으로 90도 회전
		2. 바라보는 방향 기준 앞쪽 칸이 청소되지 않은 빈칸일 경우 한 칸 전진
		3. 1번으로 돌아감
*/

#define MAX 50
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int room[MAX][MAX];
int N, M;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool isClean[MAX][MAX];

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M) {
		return true;
	}

	return false;
}

bool checkNearAllClean(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!inRange(ny, nx)) {
			continue;
		}

		if (room[ny][nx] == 1) {
			continue;
		}
		
		if (!isClean[ny][nx]) {
			return false;
		}
	}
	return true;
}

pair<int, int> moveBack(int y, int x, int d) {
	switch (d) {
	case UP:
		y++;
		break;
	case DOWN:
		y--;
		break;
	case LEFT:
		x++;
		break;
	case RIGHT:
		x--;
		break;
	}

	if (!inRange(y, x)) {
		return { -1, -1 };
	}

	if (room[y][x] == 1) {
		return { -1, -1 };
	}

	return { y, x };
}

int solve(int initY, int initX, int initD) {
	int y = initY, x = initX, d = initD;
	int result = 0;

	while (true) {
		// 1. check present
		if (!isClean[y][x]) {
			result++;
			isClean[y][x] = true;
		}

		// 2. check near 4
		bool isAllClean = checkNearAllClean(y, x);

		// 3. check 3
		if (isAllClean) {
			pair<int, int> next = moveBack(y, x, d);

			if (next.first == -1 && next.second == -1) {
				return result;
			}

			y = next.first;
			x = next.second;
		} else {
			for (int i = 1; i <= 4; i++) {
				int nextDirect = (d - i) % 4;
				if (nextDirect < 0) {
					nextDirect += 4;
				}

				int ny = y + dy[nextDirect];
				int nx = x + dx[nextDirect];
				
				if (inRange(ny, nx) && room[ny][nx] == 0 && !isClean[ny][nx]) {
					y = ny;
					x = nx;
					d = nextDirect;
					break;
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

	int initY, initX, initD;
	cin >> initY >> initX >> initD;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> room[y][x];
		}
	}

	cout << solve(initY, initX, initD) << '\n';

	return 0;
}