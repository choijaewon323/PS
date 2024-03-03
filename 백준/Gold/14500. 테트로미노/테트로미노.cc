#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> first[2] = {
	{{0, 0}, {0, 1}, {0, 2}, {0, 3} },
	{{0, 0}, {1, 0}, {2, 0}, {3, 0} }
};

vector<pair<int, int>> second = { {0,0}, {0, 1}, {1, 0}, {1,1} };

vector<pair<int, int>> third[8] = {
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {-1, 0}, {-2, 0}, {-2, -1}},
	{{0, 0}, {-1, 0}, {-2, 0}, {-2, 1}},
	{{0, 0}, {0, -1}, {0, -2}, {1, -2}},
	{{0, 0}, {0, -1}, {0, -2}, {-1, -2}}
};

vector<pair<int, int>> fourth[4] = {
	{{0,0}, {0, 1}, {-1, 1}, {-1, 2}},
	{{0,0}, {0, 1}, {1, 1}, {1, 2}},
	{{0,0}, {1, 0}, {1, -1}, {2, -1}},
	{{0,0}, {1, 0}, {1, 1}, {2, 1}}
};

vector<pair<int, int>> fifth[4] = {
	{{0,0}, {0, 1}, {-1, 1}, {0, 2}},
	{{0,0}, {0, 1}, {1, 1}, {0, 2}},
	{{0,0}, {1, 0}, {1, -1}, {2, 0}},
	{{0,0}, {1, 0}, {1, 1}, {2, 0}}
};

int N, M;
int numbers[500][500];

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M) {
		return true;
	}
	return false;
}

int calculate(int y, int x) {
	int result = 0;

	for (int i = 0; i < 2; i++) {
		int temp = 0;
		for (pair<int, int> &p : first[i]) {
			int ny = y + p.first;
			int nx = x + p.second;

			if (inRange(ny, nx)) {
				temp += numbers[ny][nx];
			} else {
				temp = -1;
				break;
			}
		}
		result = max(result, temp);
	}

	int tmp = 0;
	for (pair<int, int> &p : second) {
		int ny = y + p.first;
		int nx = x + p.second;

		if (inRange(ny, nx)) {
			tmp += numbers[ny][nx];
		} else {
			tmp = -1;
			break;
		}
	}
	result = max(result, tmp);

	for (int i = 0; i < 8; i++) {
		int temp = 0;
		for (pair<int, int> &p : third[i]) {
			int ny = y + p.first;
			int nx = x + p.second;

			if (inRange(ny, nx)) {
				temp += numbers[ny][nx];
			} else {
				temp = -1;
				break;
			}
		}
		result = max(result, temp);
	}

	for (int i = 0; i < 4; i++) {
		int temp = 0;
		for (pair<int, int> &p : fourth[i]) {
			int ny = y + p.first;
			int nx = x + p.second;

			if (inRange(ny, nx)) {
				temp += numbers[ny][nx];
			} else {
				temp = -1;
				break;
			}
		}
		result = max(result, temp);
	}

	for (int i = 0; i < 4; i++) {
		int temp = 0;
		for (pair<int, int> &p : fifth[i]) {
			int ny = y + p.first;
			int nx = x + p.second;

			if (inRange(ny, nx)) {
				temp += numbers[ny][nx];
			} else {
				temp = -1;
				break;
			}
		}
		result = max(result, temp);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> numbers[y][x];
		}
	}

	int answer = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			answer = max(answer, calculate(y, x));
		}
	}

	cout << answer << '\n';

	return 0;
}