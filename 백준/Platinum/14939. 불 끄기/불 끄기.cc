#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
#include <algorithm>
using namespace std;

#define MAX 10
#define INF 10000000

vector<int> matrix;
bool pushed[MAX][MAX];

void init() {
	matrix = vector<int>(MAX, 0);
}

bool isEnd(vector<int>& temp) {
	for (int i = 0; i < MAX; i++) {
		if (temp[i] != 0) {
			return false;
		}
	}
	return true;
}

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool inRange(int y, int x) {
	if (0 <= y && y < MAX && 0 <= x && x < MAX) {
		return true;
	}
	return false;
}

void flip(int y, int x, vector<int>& matrix) {
	matrix[y] = matrix[y] ^ (1 << (9 - x));
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (inRange(ny, nx)) {
			matrix[ny] = matrix[ny] ^ (1 << (9 - nx));
		}
	}
}

int calculate() {
	vector<int> temp = matrix;

	int answer = 0;
	for (int y = 1; y < MAX; y++) {
		for (int x = 0; x < MAX; x++) {
			int upper = temp[y - 1] & (1 << (9 - x));

			if (upper != 0) {
				flip(y, x, temp);
				answer++;
			}
		}
	}

	if (isEnd(temp)) {
		return answer;
	}

	return INF;
}

int solve(int x) {
	if (x == 10) {
		return calculate();
	}

	int result = INF;
	
	// no click
	result = min(solve(x + 1), result);

	// click
	flip(0, x, matrix);
	result = min(solve(x + 1) + 1, result);
	flip(0, x, matrix);

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	
	for (int y = 0; y < MAX; y++) {
		for (int x = 0; x < MAX; x++) {
			char temp;
			cin >> temp;

			if (temp == '#') {

			} else {
				matrix[y] |= 1 << (9 - x);
			}
		}
	}

	int answer = solve(0);

	if (answer == INF) {
		cout << -1 << '\n';
	} else {
		cout << answer << '\n';
	}

	return 0;
}