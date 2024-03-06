#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

int R, C;
int answer;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
char board[20][20];
bool visited[20][20];
bool alphaVisited[26];

bool inRange(int y, int x) {
	if (0 <= y && y < R && 0 <= x && x < C) {
		return true;
	}
	return false;
}

void solve(int y, int x, int cnt) {
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (inRange(ny, nx) && !visited[ny][nx] && !alphaVisited[board[ny][nx] - 'A']) {
			visited[ny][nx] = true;
			alphaVisited[board[ny][nx] - 'A'] = true;
			solve(ny, nx, cnt + 1);
			visited[ny][nx] = false;
			alphaVisited[board[ny][nx] - 'A'] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> board[y][x];
		}
	}

	visited[0][0] = true;
	alphaVisited[board[0][0] - 'A'] = true;
	solve(0, 0, 1);

	cout << answer << '\n';

	return 0;
}