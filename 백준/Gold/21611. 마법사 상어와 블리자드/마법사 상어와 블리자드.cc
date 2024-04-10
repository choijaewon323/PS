#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	크기가 N x N
	N은 항상 홀수
	1,1부터 시작
	마법사 상어는 (N + 1) / 2, (N + 1) / 2 에 있음

	가장 처음 상어가 있는 칸 제외한 나머지 칸에는 구슬
	하나 들어갈 수 있음

	같은 번호를 가진 구슬이 번호가 연속하는 칸에 있으면,
	그 구슬을 연속하는 구슬이라고 함

	방향은 위아왼오, 정수 1234로 표현함

*/

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4

vector<vector<int>> matrix;
int N, M;
int one, two, three;

bool inRange(int y, int x) {
	if (1 <= y && y <= N && 1 <= x && x <= N) {
		return true;
	}

	return false;
}

pair<int, int> nextPos(int y, int x, int direction) {
	switch (direction) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	return { y, x };
}

void readOrder() {
	int y = (N + 1) / 2;
	int x = (N + 1) / 2;
	int direction = LEFT;
	int result = 1;
	int dist = 1;
	int cnt = 0;

	while (true) {
		for (int i = 0; i < dist; i++) {
			pair<int, int> next = nextPos(y, x, direction);
			if (!inRange(next.first, next.second)) {
				return;
			}
			y = next.first;
			x = next.second;
			matrix[y][x] = result++;
		}
		direction++;
		direction %= 4;
		cnt++;
		if (cnt == 2) {
			cnt = 0;
			dist++;
		}
	}
}

void destroy(int d, int s) {
	int y = (N + 1) / 2;
	int x = (N + 1) / 2;

	switch (d) {
	case NORTH:
		for (int i = 0; i < s; i++) {
			y--;
			matrix[y][x] = 0;
		}
		break;
	case SOUTH:
		for (int i = 0; i < s; i++) {
			y++;
			matrix[y][x] = 0;
		}
		break;
	case WEST:
		for (int i = 0; i < s; i++) {
			x--;
			matrix[y][x] = 0;
		}
		break;
	case EAST:
		for (int i = 0; i < s; i++) {
			x++;
			matrix[y][x] = 0;
		}
		break;
	}
}

vector<int> readByOrder() {
	int y = (N + 1) / 2;
	int x = (N + 1) / 2;
	int direction = LEFT;
	vector<int> result;
	int dist = 1;
	int cnt = 0;

	while (true) {
		for (int i = 0; i < dist; i++) {
			pair<int, int> next = nextPos(y, x, direction);
			if (!inRange(next.first, next.second)) {
				return result;
			}
			y = next.first;
			x = next.second;
			if (matrix[y][x] != 0) {
				result.push_back(matrix[y][x]);
			}
		}
		direction++;
		direction %= 4;
		cnt++;
		if (cnt == 2) {
			cnt = 0;
			dist++;
		}
	}

	return result;
}

void insert(vector<int>& arr) {
	int size = arr.size();
	vector<vector<int>> result(N + 1, vector<int>(N + 1, 0));

	int y = (N + 1) / 2;
	int x = (N + 1) / 2;
	int direction = LEFT;
	int index = 0;
	int dist = 1;
	int cnt = 0;

	while (true) {
		for (int i = 0; i < dist; i++) {
			pair<int, int> next = nextPos(y, x, direction);
			if (!inRange(next.first, next.second)) {
				matrix = result;
				return;
			}
			y = next.first;
			x = next.second;
			if (index == size) {
				matrix = result;
				return;
			}
			result[y][x] = arr[index++];
		}
		direction++;
		direction %= 4;
		cnt++;
		if (cnt == 2) {
			cnt = 0;
			dist++;
		}
	}
}

void print() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cout << matrix[y][x] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}

vector<int> explosion(vector<int> input) {
	vector<int> rest;
	vector<int> temp;
	int initialSize = input.size();

	for (int i : input) {
		if (temp.empty()) {
			temp.push_back(i);
		} else {
			if (temp.back() == i) {
				temp.push_back(i);
			} else {
				if (temp.size() >= 4) {
					if (temp.back() == 1) {
						one += temp.size();
					} else if (temp.back() == 2) {
						two += temp.size();
					} else if (temp.back() == 3) {
						three += temp.size();
					}
				} else {
					for (int j : temp) {
						rest.push_back(j);
					}
				}

				temp.clear();
				temp.push_back(i);
			}
		}
	}
	if (temp.size() >= 4) {
		if (temp.back() == 1) {
			one += temp.size();
		} else if (temp.back() == 2) {
			two += temp.size();
		} else if (temp.back() == 3) {
			three += temp.size();
		}
	} else {
		for (int j : temp) {
			rest.push_back(j);
		}
	}

	if (rest.size() == initialSize) {
		return rest;
	} else {
		return explosion(rest);
	}
}

vector<int> group(vector<int> input) {
	vector<int> rest;
	vector<int> temp;
	int initialSize = input.size();

	for (int i : input) {
		if (temp.empty()) {
			temp.push_back(i);
		} else {
			if (temp.back() == i) {
				temp.push_back(i);
			} else {
				int B = temp.back();
				int A = temp.size();

				rest.push_back(A);
				rest.push_back(B);

				temp.clear();
				temp.push_back(i);
			}
		}
	}
	
	if (!temp.empty()) {
		int B = temp.back();
		int A = temp.size();

		rest.push_back(A);
		rest.push_back(B);
	}

	return rest;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	matrix = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> matrix[y][x];
		}
	}
	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;

		destroy(d, s);
		vector<int> temp = readByOrder();

		vector<int> expResult = explosion(temp);
		vector<int> result = group(expResult);
		insert(result);
	}

	cout << one + 2 * two + 3 * three << '\n';

	return 0;
}