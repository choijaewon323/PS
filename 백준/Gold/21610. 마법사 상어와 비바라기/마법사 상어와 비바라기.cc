#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define LEFT 0
#define UPLEFT 1
#define UP 2
#define UPRIGHT 3
#define RIGHT 4
#define DOWNRIGHT 5
#define DOWN 6
#define DOWNLEFT 7

vector<vector<int>> bucket;
vector<vector<bool>> cloud;
int N, M;
int dy[] = { -1, -1, 1, 1 };
int dx[] = { -1, 1, -1, 1 };

void cloudInit() {
	cloud[N - 1][0] = true;
	cloud[N - 1][1] = true;
	cloud[N - 2][0] = true;
	cloud[N - 2][1] = true;
}

pair<int, int> nextPos(int y, int x, int d, int s) {
	switch (d) {
	case LEFT:
		x -= s;
		break;
	case UPLEFT:
		y -= s;
		x -= s;
		break;
	case UP:
		y -= s;
		break;
	case UPRIGHT:
		y -= s;
		x += s;
		break;
	case RIGHT:
		x += s;
		break;
	case DOWNRIGHT:
		y += s;
		x += s;
		break;
	case DOWN:
		y += s;
		break;
	case DOWNLEFT:
		y += s;
		x -= s;
		break;
	}

	y %= N;
	x %= N;

	if (y < 0) {
		y += N;
	}
	if (x < 0) {
		x += N;
	}

	return { y, x };
}

void moveCloud(int d, int s) {
	vector<vector<bool>> nextCloud(N, vector<bool>(N, false));
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (cloud[y][x]) {
				pair<int, int> next = nextPos(y, x, d, s);

				nextCloud[next.first][next.second] = true;
			}
		}
	}

	cloud = nextCloud;
}

void plusWater() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (cloud[y][x]) {
				bucket[y][x]++;
			}
		}
	}
}

bool inRange(int y, int x) {
	return (0 <= y && y < N && 0 <= x && x < N);
}

void waterMagic() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (cloud[y][x]) {
				int cnt = 0;

				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (inRange(ny, nx) && bucket[ny][nx] >= 1) {
						cnt++;
					}
				}

				bucket[y][x] += cnt;
			}
		}
	}
}

void makeCloud() {
	vector<vector<bool>> nextCloud(N, vector<bool>(N, false));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (cloud[y][x]) {
				continue;
			}

			if (bucket[y][x] >= 2) {
				nextCloud[y][x] = true;
				bucket[y][x] -= 2;
			}
		}
	}

	cloud = nextCloud;
}

long long calculateResult() {
	long long result = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			result += bucket[y][x];
		}
	}

	return result;
}

void printCloud() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << cloud[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	bucket = vector<vector<int>>(N, vector<int>(N));
	cloud = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> bucket[y][x];
		}
	}
	
	cloudInit();
	
	for (int i = 0; i < M; i++) {
		int d, s;

		cin >> d >> s;
		moveCloud(d - 1, s);
		plusWater();
		waterMagic();
		makeCloud();
	}
	
	cout << calculateResult() << '\n';

	return 0;
}