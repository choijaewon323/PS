#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

/*
	공기청정기 성능 테스트
	집 크기 R x C
	
	공기청정기는 항상 1번 열에 설치,크기는 두 행을 차지

	공기청정기가 설치되지 않은 칸에는 미세먼지, A[r][c]만큼

	1초 동안 순서대로 아래 일 발생
	1. 미세먼지 확산 -> 미세먼지 모든 칸 동시 발생
		(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산
		인접 방향 공기청정기 or 칸이 없으면 확산 x
		확산되는 양은 A[r][c] / 5 이고 소수점 버림
		A[r][c]에 남은 미세먼지 양은 A[r][c] - (A[r][c]/5) * 확산된 개수
	2. 공기청정기 작동
		바람 나옴
		위쪽 공기청정기의 바람은 반시계방향 순환, 아래쪽은 시계방향 순환
		바람이 불면 미세먼지가 바람의 방향대로 모두 한칸씩 이동
		공기청정기로 미세먼지가 들어가면 없어짐

*/

int R, C, T;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int up, down;
vector<vector<int>> A;

bool inRange(int y, int x) {
	if (0 <= y && y < R && 0 <= x && x < C) {
		return true;
	}

	return false;
}

void spread() {
	vector<vector<int>> result(R, vector<int>(C, 0));

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (A[y][x] == -1) {
				result[y][x] = -1;
				continue;
			}

			int present = A[y][x];
			int cnt = 0;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (!inRange(ny, nx)) {
					continue;
				}
				if (A[ny][nx] == -1) {
					continue;
				}

				cnt++;
				int next = present / 5;
				result[ny][nx] += next;
			}

			result[y][x] += present - (present / 5 * cnt);
		}
	}
	A = result;
}

void upFunc() {
	queue<int> q;
	int startY, startX;

	// right
	startY = up;
	for (int x = 1; x < C; x++) {
		q.push(A[startY][x]);
	}

	// up
	startX = C - 1;
	for (int y = up - 1; y >= 0; y--) {
		q.push(A[y][startX]);
	}

	// left
	startY = 0;
	for (int x = C - 2; x >= 0; x--) {
		q.push(A[startY][x]);
	}

	// down
	startX = 0;
	for (int y = 1; y <= up - 2; y++) {
		q.push(A[y][startX]);
	}

	A[up][1] = 0;
	for (int x = 2; x <= C - 1; x++) {
		A[up][x] = q.front();
		q.pop();
	}

	for (int y = up - 1; y >= 0; y--) {
		A[y][C - 1] = q.front();
		q.pop();
	}

	for (int x = C - 2; x >= 0; x--) {
		A[0][x] = q.front();
		q.pop();
	}

	for (int y = 1; y <= up - 1; y++) {
		A[y][0] = q.front();
		q.pop();
	}
}

void downFunc() {
	queue<int> q;
	
	for (int x = 1; x <= C - 1; x++) {
		q.push(A[down][x]);
	}
	for (int y = down + 1; y <= R - 1; y++) {
		q.push(A[y][C - 1]);
	}
	for (int x = C - 2; x >= 0; x--) {
		q.push(A[R - 1][x]);
	}
	for (int y = R - 2; y >= down + 2; y--) {
		q.push(A[y][0]);
	}

	A[down][1] = 0;
	for (int x = 2; x <= C - 1; x++) {
		A[down][x] = q.front();
		q.pop();
	}
	for (int y = down + 1; y <= R - 1; y++) {
		A[y][C - 1] = q.front();
		q.pop();
	}
	for (int x = C - 2; x >= 0; x--) {
		A[R - 1][x] = q.front();
		q.pop();
	}
	for (int y = R - 2; y >= down + 1; y--) {
		A[y][0] = q.front();
		q.pop();
	}
}

void airCondition() {
	upFunc();
	downFunc();
}

int calculate() {
	int result = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (A[y][x] == -1) {
				continue;
			}

			result += A[y][x];
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	up = -1;
	down = -1;

	cin >> R >> C >> T;
	A = vector<vector<int>>(R, vector<int>(C, 0));
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> A[y][x];

			// up
			if (A[y][x] == -1 && up == -1) {
				up = y;
			
			} else if (A[y][x] == -1 && up != -1) { // down
				down = y;
			}
		}
	}

	for (int second = 0; second < T; second++) {
		// 1. spread
		spread();

		// 2. air conditioner
		airCondition();
	}

	cout << calculate() << '\n';

	return 0;
}