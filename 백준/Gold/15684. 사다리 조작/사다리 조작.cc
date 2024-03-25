#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	어떻게 i번 세로선의 결과가 i번이 나오게 만들 수 있을까?

	9 * 30 = 270

	완탐으로 가능

	
*/

#define MAX 32

int N, M, H;
bool edge[MAX + 1][MAX + 1][MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1][MAX + 1][MAX + 1];

int execute(int y, int x) {
	if (y == H + 1) {
		return x;
	}

	int result = -1;

	// check left
	if (edge[y][x][y][x - 1] && !visited[y][x][y][x - 1]) {
		visited[y][x][y][x - 1] = true;
		visited[y][x - 1][y][x] = true;
		result = execute(y, x - 1);
		visited[y][x][y][x - 1] = false;
		visited[y][x - 1][y][x] = false;

	} else if (edge[y][x][y][x + 1] && !visited[y][x][y][x + 1]) {
		visited[y][x][y][x + 1] = true;
		visited[y][x + 1][y][x] = true;
		result = execute(y, x + 1);
		visited[y][x][y][x + 1] = false;
		visited[y][x + 1][y][x] = false;
	
	} else {
		result = execute(y + 1, x);
	}

	return result;
}

bool isPossible() {
	for (int i = 1; i <= N; i++) {
		int result = execute(0, i);
		
		if (result != i) {
			return false;
		}
	}
	
	return true;
}

bool addLine(int prevY, int prevX, int addCnt, int goalCnt) {
	if (addCnt == goalCnt) {
		if (isPossible()) {
			return true;
		}
		return false;
	}

	for (int y = prevY; y <= H; y++) {
		if (y == prevY) {
			for (int x = prevX; x <= N - 1; x++) {
				if (edge[y][x][y][x + 1]) {
					continue;
				}

				if (!edge[y][x][y][x - 1] && !edge[y][x + 1][y][x + 2]) {
					edge[y][x][y][x + 1] = true;
					edge[y][x + 1][y][x] = true;
					bool result = addLine(y, x, addCnt + 1, goalCnt);
					edge[y][x][y][x + 1] = false;
					edge[y][x + 1][y][x] = false;

					if (result) {
						return true;
					}
				}
			}
		
		} else {
			for (int x = 1; x <= N - 1; x++) {
				if (edge[y][x][y][x + 1]) {
					continue;
				}

				if (!edge[y][x][y][x - 1] && !edge[y][x + 1][y][x + 2]) {
					edge[y][x][y][x + 1] = true;
					edge[y][x + 1][y][x] = true;
					bool result = addLine(y, x, addCnt + 1, goalCnt);
					edge[y][x][y][x + 1] = false;
					edge[y][x + 1][y][x] = false;

					if (result) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;

		edge[a][b][a][b + 1] = true;
		edge[a][b + 1][a][b] = true;
	}

	if (isPossible()) {
		cout << 0 << '\n';

		return 0;
	}

	// add
	for (int cnt = 1; cnt <= 3; cnt++) {
		bool result = addLine(1, 1, 0, cnt);

		if (result) {
			cout << cnt << '\n';

			return 0;
		}
	}

	cout << -1 << '\n';

	return 0;
}