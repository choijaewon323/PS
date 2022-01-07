#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int paper[501][501];
int n;
int m;
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
bool discovered[501][501];
void dfs(int startY, int startX, int length, int temp, vector<int>& answers) {
	if (length == 4) {
		answers.push_back(temp);
		return;
	}
	discovered[startY][startX] = true;
	for (int i = 0; i < 4; i++) {
		int y = startY + dy[i];
		int x = startX + dx[i];
		if (y >= 1 && y <= n && x >= 1 && x <= m) {
			if (!discovered[y][x])
			dfs(y, x, length + 1, temp + paper[y][x], answers);
		}
	}
	discovered[startY][startX] = false;
}
int func(int startY, int startX) {
	int result = 0;
	int dy[][4] = { 
		{0, 0, 1, 0},{0, 1, 1, 2},
		{0, 0, -1, 0}, {0, -1, -1, -2}
	};
	int dx[][4] = { 
		{0, 1, 1, 2}, {0, 0, -1, 0},
		{0, -1, -1, -2}, {0, 0, 1, 0}
	};
	for (int i = 0; i < 4; i++) {
		int y1 = startY + dy[i][0];
		int x1 = startX + dx[i][0];
		int y2 = startY + dy[i][1];
		int x2 = startX + dx[i][1];
		int y3 = startY + dy[i][2];
		int x3 = startX + dx[i][2];
		int y4 = startY + dy[i][3];
		int x4 = startX + dx[i][3];
		if (y1 >= 1 && y1 <= n && x1 >= 1 && x1 <= m &&
			y2 >= 1 && y2 <= n && x2 >= 1 && x2 <= m &&
			y3 >= 1 && y3 <= n && x3 >= 1 && x3 <= m &&
			y4 >= 1 && y4 <= n && x4 >= 1 && x4 <= m) {
			result = max(result, paper[y1][x1] + paper[y2][x2] + paper[y3][x3] + paper[y4][x4]);
		}
	}
	vector<int> dfsAnswers;
	dfs(startY, startX, 1, paper[startY][startX], dfsAnswers);
	sort(dfsAnswers.begin(), dfsAnswers.end());
	result = max(result, dfsAnswers.back());
	return result;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> paper[i][j];
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			result = max(result, func(i, j));
		}
	}
	cout << result << '\n';
	return 0;
}