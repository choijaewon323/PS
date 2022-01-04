#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int maps[8][8];
int bfs(int n, int m, vector<vector<int>>& tempMap,
	vector<pair<int, int>>& indexOfVirus) {
	queue<pair<int, int>> q;
	int dy[] = { -1, 0, 0, 1 };
	int dx[] = { 0, -1, 1, 0 };
	for (auto virus : indexOfVirus) {
		q.push(virus);
	}
	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int y = present.first + dy[i];
			int x = present.second + dx[i];
			if (y >= 0 && y < n && x >= 0 && x < m) {
				if (tempMap[y][x] == 0) {
					tempMap[y][x] = 2;
					q.push(make_pair(y, x));
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tempMap[i][j] == 0) {
				result++;
			}
		}
	}
	return result;
}
int func(int n, int m, vector<pair<int, int>>& indexOfBlank, vector<pair<int, int>>& indexOfVirus) {
	int result = 0;
	for (int i = 0; i < indexOfBlank.size() - 2; i++) {
		for (int j = i + 1; j < indexOfBlank.size() - 1; j++) {
			for (int k = j + 1; k < indexOfBlank.size(); k++) {
				vector<vector<int>> tempMap(n);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						tempMap[i].push_back(maps[i][j]);
					}
				}
				tempMap[indexOfBlank[i].first][indexOfBlank[i].second] = 1;
				tempMap[indexOfBlank[j].first][indexOfBlank[j].second] = 1;
				tempMap[indexOfBlank[k].first][indexOfBlank[k].second] = 1;
				result = max(result, bfs(n, m, tempMap, indexOfVirus));
			}
		}
	}
	return result;
}
int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			maps[i][j] = 1;
		}
	}
	int n, m;
	vector<pair<int, int>> indexOfBlank;
	vector<pair<int, int>> indexOfVirus;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
			if (!maps[i][j]) {
				indexOfBlank.push_back(make_pair(i, j));
			}
			if (maps[i][j] == 2) {
				indexOfVirus.push_back(make_pair(i, j));
			}
		}
	}
	cout << func(n, m, indexOfBlank, indexOfVirus) << '\n';
	return 0;
}