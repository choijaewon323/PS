/*
	상어 1이상 M이하 자연수 번호 부여 - 모든 번호 서로 다름
	1이 가장 강력 -> 나머지 모두 쫓을 수 있음

	N x N 격자, M개 칸에 상어가 한마리씩 들어있ㅇㅁ

	1. 모든 상어가 자신의 위치에 자신의 냄새 뿌림
	2. 1초마다 모든 상어가 동시에 상하좌우로 인접한 칸 중 하나로 이동, 자신의 냄새 뿌림

	냄새는 상어가 k번 이동하고 나면 사라짐

	이동 방향 결정
	- 인접 칸중 아무 냄새 없는 칸의 방향으로 잡음
	- 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향
	- 가능한 칸 여러개일 수 있음, 그 경우 특정 우선순위 따름
	상어가 맨 처음 보고있는 방향 입력으로, 그 후 방금 이동한 방향이 보고 있는 방향

	모든 상어 이동 후 한 칸에 여러 마리 상어 있ㄷ으면, 가장 작은 번호 상어 빼고 다 쫓겨남

	이 과정을 반복, 1번 상어만 격자에 남을 때까지 몇 초 걸리는지 구하기

	N, M, K (2 <= N <= 20, 2 <= M <= 400, 1 <= k <= 1,000)

	0은 빈칸, 0이 아닌 수 x는 x번 상어

	방향 -> 1, 2, 3, 4 는 각각 위, 아래, 왼쪽, 오른쪽 의미 (1씩 줄여서 0 1 2 3 으로 하면 깔끔할듯)

	1,000 초가 넘어도 다른 상어가 격자에 남아있으면 -1 출력 (최대 1,000 초)
	

	냄새 자취에 대한 배열과 상어 배열을 따로 놓는다면?
*/

#include <iostream>
#include <vector>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


// true : 냄새 적용 / false : empty
struct smellNode {
	bool state;
	int sharkNum;
	int sec;
};

struct shark {
	int num;
	int presentDirect;
	int direct[4][4];
};

smellNode smells[20][20];
vector<vector<int>> matrix(20, vector<int>(20, 0));
shark sharkInfo[401];
int N, M, k;

bool checkDone() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (matrix[y][x] == 0 || matrix[y][x] == 1) {
				continue;
			}
			return false;
		}
	}

	return true;
}

void smellMinus() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (smells[y][x].state) {
				(smells[y][x].sec)--;

				if (smells[y][x].sec == 0) {
					smells[y][x].state = false;
				}
			}
		}
	}
}

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N) {
		return true;
	}
	return false;
}

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void sharkMove() {
	vector<vector<int>> result(20, vector<int>(20, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (matrix[y][x]) {
				int sharkNum = matrix[y][x];

				int present = sharkInfo[sharkNum].presentDirect;
				int nextY = -1;
				int nextX = -1;
				int nDirect = -1;
				bool flag = false;

				// 1. find empty space
				for (int i = 0; i < 4; i++) {
					int nextDirect = (sharkInfo[sharkNum].direct)[present][i];
					int ny = y + dy[nextDirect];
					int nx = x + dx[nextDirect];

					if (inRange(ny, nx) && smells[ny][nx].state == false) {
						flag = true;
						nextY = ny;
						nextX = nx;
						nDirect = nextDirect;
						break;
					}
				}

				if (flag) {
					if (result[nextY][nextX] != 0) {
						if (result[nextY][nextX] > sharkNum) {
							result[nextY][nextX] = sharkNum;
							sharkInfo[sharkNum].presentDirect = nDirect;
						}
					}
					else {
						result[nextY][nextX] = sharkNum;
						sharkInfo[sharkNum].presentDirect = nDirect;
					}

					continue;
				}

				// 2. find my smell space
				for (int i = 0; i < 4; i++) {
					int nextDirect = (sharkInfo[sharkNum].direct)[present][i];
					int ny = y + dy[nextDirect];
					int nx = x + dx[nextDirect];

					if (inRange(ny, nx) && smells[ny][nx].sharkNum == sharkNum) {
						flag = true;
						nextY = ny;
						nextX = nx;
						nDirect = nextDirect;
						break;
					}
				}

				if (flag) {
					if (result[nextY][nextX] != 0) {
						if (result[nextY][nextX] > sharkNum) {
							result[nextY][nextX] = sharkNum;
							sharkInfo[sharkNum].presentDirect = nDirect;
						}
					}
					else {
						result[nextY][nextX] = sharkNum;
						sharkInfo[sharkNum].presentDirect = nDirect;
					}
					continue;
				}
			}
		}
	}

	matrix = result;
}

void printMatrix() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << matrix[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void printSmell() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << smells[y][x].sharkNum << "," << smells[y][x].sec << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> k;

	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			smells[y][x] = { false, 0 };
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int temp;
			cin >> temp;

			matrix[y][x] = temp;
		}
	}

	for (int i = 1; i <= M; i++) {
		int direct;
		cin >> direct;

		sharkInfo[i].presentDirect = direct - 1;
	}

	for (int i = 1; i <= M; i++) {
		for (int d = 0; d < 4; d++) {
			for (int nd = 0; nd < 4; nd++) {
				int direct;
				cin >> direct;

				sharkInfo[i].direct[d][nd] = direct - 1;
			}
		}
	}

	// before : 냄새 뿌리기
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (matrix[y][x]) {
				smells[y][x].sec = k;
				smells[y][x].sharkNum = matrix[y][x];
				smells[y][x].state = true;
			}
		}
	}

	int answer = -1;

	for (int second = 1; second <= 1000; second++) {
		

		// 1. shark move
		sharkMove();

		// 2. smell discount
		smellMinus();

		// 3. smell spread
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (matrix[y][x]) {
					smells[y][x].sec = k;
					smells[y][x].sharkNum = matrix[y][x];
					smells[y][x].state = true;
				}
			}
		}
		
		// 4. check done
		if (checkDone()) {
			answer = second;
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}