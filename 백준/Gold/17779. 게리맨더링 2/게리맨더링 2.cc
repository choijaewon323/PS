#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 20
#define INF 1000000000

int N;
int world[MAX + 1][MAX + 1];
int allSum;

bool isPossible(int y, int x, int d1, int d2) {
	if (y + d1 + d2 > N) {
		return false;
	}
	if (1 > x - d1) {
		return false;
	}
	if (x + d2 > N) {
		return false;
	}
	return true;
}

vector<vector<bool>> drawLine(int y, int x, int d1, int d2) {
	vector<vector<bool>> section(N + 1, vector<bool>(N + 1, false));
	// 1
	int y1 = y;
	int x1 = x;
	int y2 = y + d2;
	int x2 = x + d2;
	section[y1][x1] = true;
	section[y2][x2] = true;
	for (int i = 1; i <= d1; i++) {
		y1++;
		x1--;
		y2++;
		x2--;
		section[y1][x1] = true;
		section[y2][x2] = true;
	}
	// 2
	y1 = y;
	x1 = x;
	y2 = y + d1;
	x2 = x - d1;
	section[y1][x1] = true;
	section[y2][x2] = true;
	for (int i = 1; i <= d2; i++) {
		y1++;
		x1++;
		y2++;
		x2++;
		section[y1][x1] = true;
		section[y2][x2] = true;
	}
	for (int r = y + 1; r < y + d1 + d2; r++) {
		bool flag = false;
		for (int c = 1; c <= N; c++) {
			if (!flag) {
				if (section[r][c]) {
					flag = true;
				}
			} else {
				if (section[r][c]) {
					flag = false;
				} else {
					section[r][c] = true;
				}
			}
		}
	}
	return section;
}

int first(int y, int x, int d1, int d2, vector<vector<bool>>& section) {
	int result = 0;
	for (int r = 1; r < y + d1; r++) {
		for (int c = 1; c <= x; c++) {
			if (section[r][c]) {
				continue;
			}

			result += world[r][c];
		}
	}
	return result;
}

int second(int y, int x, int d1, int d2, vector<vector<bool>> &section) {
	int result = 0;
	for (int r = 1; r <= y + d2; r++) {
		for (int c = x + 1; c <= N; c++) {
			if (section[r][c]) {
				continue;
			}

			result += world[r][c];
		}
	}
	return result;
}

int third(int y, int x, int d1, int d2, vector<vector<bool>> &section) {
	int result = 0;
	for (int r = y + d1; r <= N; r++) {
		for (int c = 1; c < x - d1 + d2; c++) {
			if (section[r][c]) {
				continue;
			}

			result += world[r][c];
		}
	}
	return result;
}

int fourth(int y, int x, int d1, int d2, vector<vector<bool>> &section) {
	int result = 0;
	for (int r = y + d2 + 1; r <= N; r++) {
		for (int c = x - d1 + d2; c <= N; c++) {
			if (section[r][c]) {
				continue;
			}

			result += world[r][c];
		}
	}
	return result;
}

int solve(int y, int x, int d1, int d2) {
	vector<vector<bool>> section = drawLine(y, x, d1, d2);
	int acc = 0;
	int minAns = INF;
	int maxAns = -1;

	int one = first(y, x, d1, d2, section);
	acc += one;
	minAns = min(minAns, one);
	maxAns = max(maxAns, one);

	int two = second(y, x, d1, d2, section);
	acc += two;
	minAns = min(minAns, two);
	maxAns = max(maxAns, two);

	int three = third(y, x, d1, d2, section);
	acc += three;
	minAns = min(minAns, three);
	maxAns = max(maxAns, three);

	int four = fourth(y, x, d1, d2, section);
	acc += four;
	minAns = min(minAns, four);
	maxAns = max(maxAns, four);

	int fifth = allSum - acc;
	minAns = min(minAns, fifth);
	maxAns = max(maxAns, fifth);

	return maxAns - minAns;
}

int solution() {
	int result = INF;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (isPossible(y, x, d1, d2)) {
						result = min(result, solve(y, x, d1, d2));
					}
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

	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> world[y][x];
			allSum += world[y][x];
		}
	}
	cout << solution() << '\n';
	return 0;
}