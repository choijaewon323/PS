#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int area[101][101];
int bfs(pair<int, int> start, vector<vector<bool>>& isNotBlocked) {
	queue<pair<int, int>> q;
	int dy[] = { -1, 0, 0, 1 };
	int dx[] = { 0, -1, 1, 0 };
	q.push(make_pair(start.first, start.second));
	isNotBlocked[start.first][start.second] = false;
	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = present.first + dy[i];
			int x = present.second + dx[i];
			if (isNotBlocked[y][x]) {
				q.push(make_pair(y, x));
				isNotBlocked[y][x] = false;
			}
		}
	}
	return 1;
}
int func(int n) {
	int result = 0;
	for (int i = 0; i <= 100; i++) {
		vector<pair<int, int>> notSinked;
		int tempResult = 0;
		vector<vector<bool>> isNotBlocked(n + 3, vector<bool>(n + 3, false));
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {
				if (area[y][x] > i) {
					notSinked.push_back(make_pair(y, x));
					isNotBlocked[y][x] = true;
				}
			}
		}
		for (auto temp : notSinked) {
			if (isNotBlocked[temp.first][temp.second]) {
				tempResult += bfs(temp, isNotBlocked);
			}
		}
		result = max(tempResult, result);
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> area[i][j];
		}
	}
	cout << func(n) << '\n';
	return 0;
}