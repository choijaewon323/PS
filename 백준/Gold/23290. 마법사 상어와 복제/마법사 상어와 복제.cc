#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
	4 x 4 격자에서 연습
	1,1에서 시작

	물고기 M마리 존재, 이동방향을 가지고 있음
	상하좌우, 대각선 중 하나

	상어도 격자의 한 칸에 들어감

	둘 이상의 물고기가 같은 칸에 있을 수도 있으며,
	마법사 상어와 물고기가 같은 칸 가능

	1. 상어가 모든 물고기 복제 -> 5번에서 물고기가 복제되어
	칸에 나타남
	2. 모든 물고기 한칸 이동
		상어가 있는 칸, 물고기의 냄새가 있는 칸, 격자의
		범위를 벗어난 칸은 불가능
		각 물고기는 자신이 가진 이동 방향이
		이동할 수 있는 칸을 향할 때까지 45도 반시계 회전
		만약 없으면 이동 안함
	3. 상어가 연속해서 3칸 이동
		상하좌우로 인접한 칸으로 이동 가능
		연속해서 이동하는 칸 중에 격자의 범위를 벗어나면
		불가능한 이동 방법
		이동 중에 상어가 물고기 칸을 이동하면 그 물고기 제외
		제외되는 물고기는 물고기 냄새를 남김
		가능한 이동 방법 중에 제외되는 물고기 수가 가장
		많은 방법으로 이동
		그러한 방법이 여러가지인 경우 사전 순으로 가장 앞서는
		방법 택함
	4. 두 번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라짐
	5. 복제 마법 완료

*/

#define MAX 4

#define LEFT 0
#define UPLEFT 1
#define UP 2
#define UPRIGHT 3
#define RIGHT 4
#define DOWNRIGHT 5
#define DOWN 6
#define DOWNLEFT 7

#define SHARK 0
#define FISH 1

struct Object {
	int state;
	int direction;
};

typedef vector<vector<vector<Object>>> VO;

int M, S;
int smell[MAX + 1][MAX + 1];
VO matrix;
bool sharkMatrix[MAX + 1][MAX + 1];

void print() {
	for (int y = 1; y <= MAX; y++) {
		for (int x = 1; x <= MAX; x++) {
			cout << matrix[y][x].size() << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

pair<int, int> nextPos(int y, int x, int direction) {
	switch (direction) {
	case LEFT:
		x--;
		break;
	case UPLEFT:
		y--;
		x--;
		break;
	case UP:
		y--;
		break;
	case UPRIGHT:
		y--;
		x++;
		break;
	case RIGHT:
		x++;
		break;
	case DOWNRIGHT:
		y++;
		x++;
		break;
	case DOWN:
		y++;
		break;
	case DOWNLEFT:
		y++;
		x--;
		break;
	}
	return { y, x };
}

bool inRange(int y, int x) {
	if (1 <= y && y <= MAX && 1 <= x && x <= MAX) {
		return true;
	}
	return false;
}

bool isSmell(int y, int x) {
	if (smell[y][x] > 0) {
		return true;
	}
	return false;
}

bool isShark(int y, int x) {
	if (sharkMatrix[y][x]) {
		return true;
	}
	return false;
}

int nextDirection(int direction) {
	direction %= 8;
	
	if (direction < 0) {
		direction += 8;
	}
	return direction;
}

void moveFish() {
	VO result = VO(MAX + 1, vector<vector<Object>>(MAX + 1));

	for (int y = 1; y <= MAX; y++) {
		for (int x = 1; x <= MAX; x++) {
			for (Object &obj : matrix[y][x]) {
				int direction = obj.direction;
				bool isMove = false;

				for (int i = 0; i < 8; i++) {
					int nextDirect = nextDirection(direction - i);

					pair<int, int> next = nextPos(y, x, nextDirect);
					int ny = next.first;
					int nx = next.second;

					if (!inRange(ny, nx)) {
						continue;
					}
					if (isSmell(ny, nx)) {
						continue;
					}
					if (isShark(ny, nx)) {
						continue;
					}
					isMove = true;
					obj.direction = nextDirect;
					result[ny][nx].push_back(obj);
					break;
				}

				if (!isMove) {
					result[y][x].push_back(obj);
				}
			}
		}
	}

	matrix = result;
}

pair<int, int> findShark() {
	for (int y = 1; y <= MAX; y++) {
		for (int x = 1; x <= MAX; x++) {
			if (sharkMatrix[y][x]) {
				return { y, x };
			}
		}
	}
	return { -1, -1 };
}
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int countFish(vector<pair<int, int>> &temp, int sy, int sx) {
	vector<vector<bool>> visited(MAX + 1, vector<bool>(MAX + 1, false));
	int result = 0;

	for (pair<int, int> &p : temp) {
		int y = p.first;
		int x = p.second;

		if (!visited[y][x]) {
			visited[y][x] = true;
			int cnt = matrix[y][x].size();

			result += cnt;
		}
	}

	return result;
}

void moveShark() {
	pair<int, int> sharkPos = findShark();
	int sy = sharkPos.first;
	int sx = sharkPos.second;
	sharkMatrix[sy][sx] = false;

	int maxCnt = -1;
	vector<pair<int, int>> result;

	for (int i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];

		if (!inRange(ny, nx)) continue;

		for (int j = 0; j < 4; j++) {
			int ny1 = ny + dy[j];
			int nx1 = nx + dx[j];

			if (!inRange(ny1, nx1)) continue;

			for (int k = 0; k < 4; k++) {
				int ny2 = ny1 + dy[k];
				int nx2 = nx1 + dx[k];

				if (!inRange(ny2, nx2)) continue;

				vector<pair<int, int>> temp;
				temp.push_back({ ny, nx });
				temp.push_back({ ny1, nx1 });
				temp.push_back({ ny2, nx2 });

				int cnt = countFish(temp, sy, sx);

				if (maxCnt < cnt) {
					result = temp;
					maxCnt = cnt;
				}
			}
		}
	}

	for (pair<int, int> &p : result) {
		if (!matrix[p.first][p.second].empty()) {
			matrix[p.first][p.second].clear();
			smell[p.first][p.second] = 3;
		}
	}

	pair<int, int> last = result.back();
	sharkMatrix[last.first][last.second] = true;
}

void deleteSmell() {
	for (int y = 1; y <= MAX; y++) {
		for (int x = 1; x <= MAX; x++) {
			if (smell[y][x] > 0) {
				smell[y][x]--;
			}
		}
	}
}

void applyReplica(VO& prev) {
	for (int y = 1; y <= MAX; y++) {
		for (int x = 1; x <= MAX; x++) {
			for (Object &obj : prev[y][x]) {
				matrix[y][x].push_back(obj);
			}
		}
	}
}

int calculate() {
	int result = 0;
	for (int y = 1; y <= MAX; y++) {
		for (int x = 1; x <= MAX; x++) {
			result += matrix[y][x].size();
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	matrix = VO(MAX + 1, vector<vector<Object>>(MAX + 1));

	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		int y, x, d;

		cin >> y >> x >> d;
		d--;
		matrix[y][x].push_back({ FISH, d });
	}
	int y, x;
	cin >> y >> x;
	sharkMatrix[y][x] = true;

	for (int magicCnt = 0; magicCnt < S; magicCnt++) {
		// 1. replica
		VO replica = matrix;
		// 2. move fish
		moveFish();
		//print();
		// 3. move shark
		moveShark();
		//print();
		// 4. delete smell
		deleteSmell();
		// 5. apply replica
		applyReplica(replica);
		//print();
	}

	cout << calculate() << '\n';

	return 0;
}