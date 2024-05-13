#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
using namespace std;

#define MAX 1000

int N, M;
int parent[MAX * MAX];
char board[MAX][MAX];
map<pair<int, int>, int> boardToNumber;

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
	int cnt = 0;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
			boardToNumber[{y, x}] = cnt;
			cnt++;
		}
	}
}

int oppositeNumber(int y, int x) {
	char present = board[y][x];
	switch (present) {
	case 'D':
		y++;
		break;
	case 'U':
		y--;
		break;
	case 'L':
		x--;
		break;
	case 'R':
		x++;
		break;
	}
	return boardToNumber[{y, x}];
}

int countOfZone() {
	int result = 0;
	vector<int> zones(N * M, false);
	for (int i = 0; i < N * M; i++) {
		int present = find(i);
		zones[present] = true;
	}
	for (int i = 0; i < N * M; i++) {
		if (zones[i]) {
			result++;
		}
	}
	return result;
}

int solve() {
	int result = 0;
	init();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int present = boardToNumber[{y, x}];
			int opposite = oppositeNumber(y, x);
			merge(present, opposite);
		}
	}
	return countOfZone();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}