/*
	4 x 4 격자에서 연습

	격자에 물고기 M마리 있음
	각 물고기는 격자 칸 하나에 들어가있고, 이동 방향 8가지중 하나 가짐
	둘 이상의 물고기가 같은 칸에 존재 가능

	1. 상어가 모든물고기에게 복제 마법 시전 : 5번에서 물고기 복제되어 나타남
	2. 모든 물고기 한칸 이동, 상어가 있는 칸, 물고기 냄새 있는 칸, 격자 범위 벗어나느 칸은
	이동할 수 없음
	각 물고기는 자신이 가지고 있는 이동 방향이 이동할 수 있는 칸을 만날 때까지 45도 반시계 회전
	3. 상어가 연속 3칸 이동, 상어는 현재 칸에서 상하좌우로 인접한 칸으로 이도 ㅇ가능
	연속해서 이동하는 칸 중 격자 범위 벗어나면 불가능
	물고기가 있는 칸으로 이동중에 만난다면 물고기는 격자에서 제외, 제외되는 물고기는 물고기 냄새 남김
	여러가지인 경우 사전 순으로 앞서는 방법 사용
	4. 두번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라짐
	5. 1에서의 복제 마법 완료

*/

#include <iostream>
#include <vector>

using namespace std;

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

struct node {
	int status;
	int direction;
};

struct shark {
	int y;
	int x;
};

vector<node> matrix[5][5];
int smell[5][5];
int M, S;
shark shrk;

bool inRange(int y, int x) {
	if (1 <= y && y <= 4 && 1 <= x && x <= 4) {
		return true;
	}
	return false;
}

int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void fishMove() {
	vector<node> temp[5][5];

	for (int y = 1; y <= 4; y++) {
		for (int x = 1; x <= 4; x++) {
			
			for (node &present : matrix[y][x]) {
				if (present.status == FISH) {
					int direction = present.direction;
					bool allFlag = false;

					for (int i = 0; i < 8; i++) {
						int nextDirect = (direction - i) % 8;

						if (nextDirect < 0) {
							nextDirect += 8;
						}
						int ny = y + dy[nextDirect];
						int nx = x + dx[nextDirect];

						if (inRange(ny, nx) && smell[ny][nx] == 0) {	// inRange, smell check
							
							if (shrk.y == ny && shrk.x == nx) {
								continue;
							}
						
							allFlag = true;
							temp[ny][nx].push_back({ FISH, nextDirect });
							break;
							
						}
					}

					if (!allFlag) {
						temp[y][x].push_back({ FISH, direction });
					}
				}
			}
		}
	}

	for (int y = 1; y <= 4; y++) {
		for (int x = 1; x <= 4; x++) {
			matrix[y][x] = temp[y][x];
		}
	}
}

int sdy[] = { -1, 0, 1, 0 };
int sdx[] = { 0, -1, 0, 1 };
string result;
int maxFish;

void process(int y, int x, string str, int acc, vector<vector<vector<node>>> tempMatrix) {
	if (str.size() == 3) {
		if (acc > maxFish) {
			maxFish = acc;
			result = str;
		}
		return;
	}

	for (int d = 0; d < 4; d++) {
		int ny = y + sdy[d];
		int nx = x + sdx[d];

		if (inRange(ny, nx)) {
			vector<node> temp = tempMatrix[ny][nx];
			
			tempMatrix[ny][nx].clear();
			
			process(ny, nx, str + (char)('0' + d), acc + temp.size(), tempMatrix);

			tempMatrix[ny][nx] = temp;
		}
	}
}

vector<vector<bool>> sharkMove() {
	vector<vector<bool>> smellResult(5, vector<bool>(5, false));
	int sy = shrk.y, sx = shrk.x;

	vector<vector<vector<node>>> tempMatrix(5, vector<vector<node>>(5, vector<node>()));

	for (int y = 1; y <= 4; y++) {
		for (int x = 1; x <= 4; x++) {
			tempMatrix[y][x] = matrix[y][x];
		}
	}

	// find max
	result = "";
	maxFish = -1;
	process(sy, sx, "", 0, tempMatrix);
	int ny = sy, nx = sx;

	for (char c : result) {
		int num = c - '0';
		
		ny = ny + sdy[num];
		nx = nx + sdx[num];

		if (!matrix[ny][nx].empty()) {
			smellResult[ny][nx] = true;
			smell[ny][nx] = 2;
			matrix[ny][nx].clear();
		}
	}

	shrk.y = ny;
	shrk.x = nx;

	return smellResult;
}

void print() {
	for (int y = 1; y <= 4; y++) {
		for (int x = 1; x <= 4; x++) {
			cout << matrix[y][x].size() << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> S;

	for (int i = 0; i < M; i++) {
		int fx, fy, d;

		cin >> fx >> fy >> d;
		d--;
		matrix[fx][fy].push_back({ FISH, d });
	}

	int sx, sy;
	cin >> sx >> sy;
	shrk = { sx, sy };

	for (int i = 0; i < S; i++) {
		// 1. replicate(not complete)
		vector<node> copy[5][5];
		for (int y = 1; y <= 4; y++) {
			for (int x = 1; x <= 4; x++) {
				copy[y][x] = matrix[y][x];
			}
		}

		// 2. fish move
		fishMove();

		// 3. shark move
		vector<vector<bool>> tempSmell = sharkMove();

		// 4. smell decrement
		for (int y = 1; y <= 4; y++) {
			for (int x = 1; x <= 4; x++) {
				if (!tempSmell[y][x] && smell[y][x] > 0) {
					smell[y][x]--;
				}
			}
		}

		// 5. replication complete
		for (int y = 1; y <= 4; y++) {
			for (int x = 1; x <= 4; x++) {
				for (node &temp : copy[y][x]) {
					matrix[y][x].push_back(temp);
				}
			}
		}
	}

	int answer = 0;

	for (int y = 1; y <= 4; y++) {
		for (int x = 1; x <= 4; x++) {
			answer += matrix[y][x].size();
		}
	}

	cout << answer << '\n';

	return 0;
}