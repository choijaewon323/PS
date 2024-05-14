#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
using namespace std;

#define MAX 1000

int N, M;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int parent[MAX * MAX];
char board[MAX][MAX];

map<pair<int, int>, int> pointToNumber;

void init() {
	for (int i = 0; i < N * M; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] != x) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	if (a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}

void input() {
	cin >> N >> M;
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
			pointToNumber[{y, x}] = cnt;
			cnt++;
		}
	}
}

bool inRange(int y, int x) {
	return (0 <= y && y < N && 0 <= x && x < M);
}

void bfs(int startY, int startX, vector<vector<int>>& zeroCnt) {
	vector<pair<int, int>> previous;
	queue<pair<int, int>> q;
	zeroCnt[startY][startX] = 1;
	previous.push_back({ startY, startX });
	q.push({ startY, startX });
	int result = 1;
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (inRange(ny, nx) && !zeroCnt[ny][nx] && board[ny][nx] == '0') {
				zeroCnt[ny][nx] = zeroCnt[y][x] + 1;
				previous.push_back({ ny, nx });
				q.push({ ny, nx });
				result++;
			}
		}
	}
	int previousSize = previous.size();
	zeroCnt[previous[0].first][previous[0].second] = result;
	for (int i = 1; i < previousSize; i++) {
		pair<int, int> prev = previous[i - 1];
		pair<int, int> now = previous[i];
		int prevNum = pointToNumber[prev];
		int nowNum = pointToNumber[now];
		zeroCnt[now.first][now.second] = result;
		merge(prevNum, nowNum);
	}
}

vector<vector<int>> getZeroCnt() {
	vector<vector<int>> zeroCnt(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] == '0' && !zeroCnt[y][x]) {
				bfs(y, x, zeroCnt);
			}
		}
	}
	return zeroCnt;
}

bool isWall(char c) {
	return (c == '1');
}

bool isAlreadyExist(vector<int> &temp, int num) {
	for (int n : temp) {
		if (n == num) {
			return true;
		}
	}
	return false;
}

vector<vector<int>> getEachCount(vector<vector<int>>& zeroCnt) {
	vector<vector<int>> result(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (isWall(board[y][x])) {
				result[y][x]++;
				vector<int> temp;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (inRange(ny, nx)) {
						int num = pointToNumber[{ny, nx}];
						int real = find(num);
						if (!isAlreadyExist(temp, real)) {
							temp.push_back(real);
							result[y][x] += zeroCnt[ny][nx];
						}
					}
				}
				result[y][x] %= 10;
			}
		}
	}
	return result;
}

vector<vector<int>> solve() {
	init();
	vector<vector<int>> zeroCnt = getZeroCnt();
	return getEachCount(zeroCnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	vector<vector<int>> answer = solve();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << answer[y][x];
		}
		cout << '\n';
	}
	return 0;
}