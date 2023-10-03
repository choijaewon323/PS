#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int N, M;
int answer[4];
vector<vector<int>> matrix;

pair<int, int> nextPos(int y, int x, int direction) {
	switch (direction) {
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
	}

	return { y, x };
}

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N) {
		return true;
	}
	return false;
}

vector<int> make() {
	vector<int> result;

	int startY = N / 2;
	int startX = N / 2;

	int di[] = { LEFT, DOWN, RIGHT, UP };
	int index = 0;

	int num = 1;

	for (int cnt = 1; cnt <= N; cnt++) {
		int nextDirect1 = di[index];
		index++;
		index %= 4;
		int nextDirect2 = di[index];
		index++;
		index %= 4;

		// 1
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect1);
			
			if (!inRange(next.first, next.second)) {
				return result;
			}

			result.push_back(matrix[next.first][next.second]);

			startY = next.first;
			startX = next.second;
		}


		// 2
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect2);

			if (!inRange(next.first, next.second)) {
				return result;
			}

			result.push_back(matrix[next.first][next.second]);

			startY = next.first;
			startX = next.second;
		}
	}
}

vector<int> traversal() {
	vector<int> result;
	int startY = N / 2;
	int startX = N / 2;

	int di[] = { LEFT, DOWN, RIGHT, UP };
	int index = 0;

	int num = 1;

	for (int cnt = 1; cnt <= N; cnt++) {
		int nextDirect1 = di[index];
		index++;
		index %= 4;
		int nextDirect2 = di[index];
		index++;
		index %= 4;

		// 1
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect1);

			if (!inRange(next.first, next.second)) {
				return result;
			}

			if (matrix[next.first][next.second] != 0) {
				result.push_back(matrix[next.first][next.second]);
			}

			startY = next.first;
			startX = next.second;
		}


		// 2
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect2);

			if (!inRange(next.first, next.second)) {
				return result;
			}

			if (matrix[next.first][next.second] != 0) {
				result.push_back(matrix[next.first][next.second]);
			}

			startY = next.first;
			startX = next.second;
		}
	}
}

vector<vector<int>> fill(vector<int> temp) {
	vector<vector<int>> result(N, vector<int>(N));

	int tempIndex = 0;
	int startY = N / 2;
	int startX = N / 2;

	int di[] = { LEFT, DOWN, RIGHT, UP };
	int index = 0;

	int num = 1;

	for (int cnt = 1; cnt <= N; cnt++) {
		int nextDirect1 = di[index];
		index++;
		index %= 4;
		int nextDirect2 = di[index];
		index++;
		index %= 4;

		// 1
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect1);

			if (!inRange(next.first, next.second)) {
				return result;
			}

			if (tempIndex < temp.size()) {
				result[next.first][next.second] = temp[tempIndex];
				tempIndex++;
			}
			else {
				result[next.first][next.second] = 0;
			}

			startY = next.first;
			startX = next.second;
		}


		// 2
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect2);

			if (!inRange(next.first, next.second)) {
				return result;
			}

			if (tempIndex < temp.size()) {
				result[next.first][next.second] = temp[tempIndex];
				tempIndex++;
			}
			else {


				result[next.first][next.second] = 0;
			}

			startY = next.first;
			startX = next.second;
		}
	}
}

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << matrix[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void magic(int d, int s) {
	int startY = N / 2;
	int startX = N / 2;

	for (int i = 0; i < s; i++) {
		pair<int, int> next = nextPos(startY, startX, d);

		matrix[next.first][next.second] = 0;
		startY = next.first;
		startX = next.second;
	}
}

void rebuild() {
	vector<int> result = traversal();

	vector<vector<int>> tempMatrix = fill(result);

	matrix = tempMatrix;
}

struct node {
	int startIndex;
	int endIndex;
	int num;
	int cnt;
};

vector<int> explodeProcess(vector<int> input) {
	vector<int> deleted(input.size(), false);
	vector<int> result;
	int endSize;

	bool flag = true;

	while (flag) {
		flag = false;
		vector<node> exp;
		node temp = { -1, -1, -1, -1 };

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == 0) {
				endSize = i;
				break;
			}

			if (deleted[i]) {
				continue;
			}

			if (temp.startIndex == -1) {
				temp = { i, -1, input[i], 1 };
			}
			else {
				if (temp.num == input[i]) {
					temp.cnt++;
				}
				else {
					if (temp.cnt >= 4) {
						flag = true;
						temp.endIndex = i - 1;
						exp.push_back(temp);
					}
					temp = { i, -1, input[i], 1 };
				}
			}
		}

		if (temp.cnt >= 4) {
			flag = true;
			temp.endIndex = endSize;
			exp.push_back(temp);
		}

		for (node &ex : exp) {
			answer[ex.num] += ex.cnt;

			for (int i = ex.startIndex; i <= ex.endIndex; i++) {
				deleted[i] = true;
			}
		}
	}

	for (int i = 0; i < deleted.size(); i++) {
		if (!deleted[i]) {
			result.push_back(input[i]);
		}
	}

	return result;
}

vector<pair<int, int>> changeProcess() {
	
	vector<pair<int, int>> result;
	pair<int, int> temp = { 0, 0 };
	int startY = N / 2;
	int startX = N / 2;

	int di[] = { LEFT, DOWN, RIGHT, UP };
	int index = 0;

	for (int cnt = 1; cnt <= N; cnt++) {
		int nextDirect1 = di[index];
		index++;
		index %= 4;
		int nextDirect2 = di[index];
		index++;
		index %= 4;

		// 1
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect1);

			if (!inRange(next.first, next.second)) {
				if (temp.second != 0)
					result.push_back(temp);
				return result;
			}

			int tempNum = matrix[next.first][next.second];

			if (tempNum != 0) {
				if (temp.second == 0) {
					temp.first = 1;
					temp.second = tempNum;
				}
				else {
					if (temp.second == tempNum) {
						temp.first++;
					}
					else {
						result.push_back(temp);
						temp.first = 1;
						temp.second = tempNum;
					}
				}
			}

			startY = next.first;
			startX = next.second;
		}


		// 2
		for (int i = 0; i < cnt; i++) {
			pair<int, int> next = nextPos(startY, startX, nextDirect2);

			if (!inRange(next.first, next.second)) {
				if (temp.second != 0)
					result.push_back(temp);
				return result;
			}

			int tempNum = matrix[next.first][next.second];

			if (tempNum != 0) {
				if (tempNum != 0) {
					if (temp.second == 0) {
						temp.first = 1;
						temp.second = tempNum;
					}
					else {
						if (temp.second == tempNum) {
							temp.first++;
						}
						else {
							result.push_back(temp);
							temp.first = 1;
							temp.second = tempNum;
						}
					}
				}
			}

			startY = next.first;
			startX = next.second;
		}
	}
}

void explode() {
	vector<int> temp = make();

	vector<int> processed = explodeProcess(temp);

	vector<vector<int>> tempMatrix = fill(processed);

	matrix = tempMatrix;
}

void change() {
	vector<pair<int, int>> temp = changeProcess();

	vector<int> input;

	for (pair<int, int> &t : temp) {
		input.push_back(t.first);
		input.push_back(t.second);
	}

	vector<vector<int>> tempMatrix = fill(input);

	matrix = tempMatrix;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	matrix = vector<vector<int>>(N, vector<int>(N));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
		}
	}

	for (int i = 0; i < M; i++) {
		int d, s;

		cin >> d >> s;
		d--;

		// 1. magic
		magic(d, s);

		// 2. rebuild
		rebuild();

		// 3. explode(inner rebuild) - 동시에 터져야 한다.
		explode();

		// 4. change(inner)
		change();
	}

	int result = answer[1] + answer[2] * 2 + answer[3] * 3;

	cout << result << '\n';

	return 0;
}