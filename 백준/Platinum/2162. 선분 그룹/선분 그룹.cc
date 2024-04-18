#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

#define COUNTER 1
#define LINE 0
#define CLOCK -1

struct Line {
	int x1;
	int y1;
	int x2;
	int y2;
};

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int result = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

	if (result > 0) {
		return COUNTER;
	} else if (result == 0) {
		return LINE;
	} else {
		return CLOCK;
	}
}

vector<Line> lines;
int parent[3000];
int N;

void init() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] != x) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

bool isIntersact(int aIndex, int bIndex) {
	Line &a = lines[aIndex];
	Line &b = lines[bIndex];

	int result1 = ccw(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
	int result2 = ccw(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
	int result3 = ccw(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
	int result4 = ccw(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

	int res12 = result1 * result2;
	int res34 = result3 * result4;

	if (res12 == 0 && res34 == 0) {
		pair<int, int> tmp1 = { a.x1, a.y1 };
		pair<int, int> tmp2 = { a.x2, a.y2 };
		pair<int, int> tmp3 = { b.x1, b.y1 };
		pair<int, int> tmp4 = { b.x2, b.y2 };

		if (tmp1 > tmp2) {
			swap(tmp1, tmp2);
		}
		if (tmp3 > tmp4) {
			swap(tmp3, tmp4);
		}

		return tmp3 <= tmp2 && tmp1 <= tmp4;
	}

	return (res12 <= 0 && res34 <= 0);
}

void merge(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot) {
		return;
	}
	
	if (aRoot < bRoot) {
		parent[bRoot] = aRoot;
	} else {
		parent[aRoot] = bRoot;
	}
}

int groupCnt[3000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	init();
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		Line newLine = { x1, y1, x2, y2 };
		lines.push_back(newLine);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (isIntersact(i, j)) {
				merge(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int root = find(i);

		groupCnt[root]++;
	}

	int ans1 = 0;
	int ans2 = -1;
	for (int i = 0; i < N; i++) {
		int num = groupCnt[i];

		if (num > 0) {
			ans1++;
			ans2 = max(ans2, num);
		}
	}

	cout << ans1 << '\n';
	cout << ans2 << '\n';

	return 0;
}