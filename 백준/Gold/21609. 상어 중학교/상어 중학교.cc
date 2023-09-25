#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

/*
	NxN 격자에서 진행, 초기 격자 모든 칸에는 블록이 하나씩 들어있다
	블록은 검은ㄴ색, 무지개, 일반 블록, 일반은 M 이하 자연수, 검은색은 -1, 무지개는 0

	블록 그룹 - 연결된 블록의 집합
	그룹에는 일반 블록이 적어도 하나 있어야함, 일반 블록의 색은 모두 같아야함
	검은색ㄱ 블록은 포함되면 안됨
	무지개는 얼마나 들어있든 상관없ㄷ음

	그룹에 속한 블록안에서는 모두 이동 가능해야함

	블록 그룹의 기준 블록은 무지개 블록이 아닌 블록 중 행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록

	오토 플레이 기능
	1. 크기가 가장 큰 블록 그룹 찾기, 그게 여러개면 포함 무지개 수가 많은 그룹, 그것도 여러개면
	기준 블록의 행이 가장 큰것, 그것도 여러개면 열이 가장 큰것
	2. 1에서 찾은 블록 그룹의 모든 블록 제거, 블록수 B에 대해 B^2점 획득
	3. 격자에 중력 작용
	4. 격자 90도 반시계 회전
	5. 다시 중력 작용

	블록 그룹 알고리즘 구상
	bfs를 사용하되, 시작할 때 0보다 큰지와 visited 안되어있는지 확인
	위쪽 오른쪽 순으로 for문을 돌리면 가능할듯
	bfs에서 주의해야 할 점은 0은 visited에 포함되면 안된다. 근데 그러면 무한 루프가 가능해짐
	일단 bfs를 돌려 0도 visited에 포함시키고 계산한 뒤, 이중 for문을 통해 0인 부분만 다시 visited 0으로 만들어줌


*/

#define DISABLE -100

int N, M;

vector<vector<int>> matrix;
vector<vector<bool>> visited;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N) {
		return true;
	}
	return false;
}

struct node {
	int cnt;
	int rainbow;
	vector<pair<int, int>> blocks;
};

node bfs(int startY, int startX) {
	int blockNum = matrix[startY][startX];
	
	node result = { 1, 0, vector<pair<int, int>>() };
	result.blocks.push_back({ startY, startX });

	queue<pair<int, int>> q;
	visited[startY][startX] = true;
	q.push({ startY, startX });

	while (!q.empty()) {
		pair<int, int> present = q.front();
		q.pop();

		if (matrix[present.first][present.second] == 0) {
			(result.rainbow)++;
		}

		for (int i = 0; i < 4; i++) {
			int ny = present.first + dy[i];
			int nx = present.second + dx[i];

			if (inRange(ny, nx) && !visited[ny][nx] &&
				(matrix[ny][nx] == 0 || matrix[ny][nx] == blockNum)) {
				result.cnt++;
				result.blocks.push_back({ ny, nx });
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	return result;
}

void down() {
	for (int x = 0; x < N; x++) {
		int top = N - 1;

		for (int y = N - 1; y >= 0; y--) {
			int present = matrix[y][x];

			if (present == DISABLE) {
				continue;
			}
			else if (present >= 0) {
				swap(matrix[top][x], matrix[y][x]);
				top--;
			}
			else if (present == -1) {
				top = y - 1;
			}
		}
	}
}

void roll() {
	vector<vector<int>> result;

	for (int x = N - 1; x >= 0; x--) {
		vector<int> temp;

		for (int y = 0; y < N; y++) {
			temp.push_back(matrix[y][x]);
		}

		result.push_back(temp);
	}

	matrix = result;
}

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (matrix[y][x] == DISABLE) {
				cout << 'D' << " ";
				continue;
			}
			cout << matrix[y][x] << " ";
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

	matrix = vector<vector<int>>(N, vector<int>(N));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
		}
	}

	long long answer = 0;

	while (true) {
		// 1. find block group
		node result = { -1, -1, vector<pair<int, int>>() };

		visited = vector<vector<bool>>(N, vector<bool>(N, 0));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (matrix[y][x] > 0 && !visited[y][x]) {
					node temp = bfs(y, x);

					if (temp.cnt == 1) {
						visited[y][x] = false;
						continue;
					}

					if (temp.cnt > result.cnt) {
						result = temp;
					}
					else if (temp.cnt == result.cnt) {
						if (temp.rainbow >= result.rainbow) {
							result = temp;
						}
					}

					for (pair<int, int> &r : temp.blocks) {
						if (matrix[r.first][r.second] == 0) {
							visited[r.first][r.second] = false;
						}
					}
				}
			}
		}

		// no block group
		if (result.cnt == -1) {
			break;
		}

		// 2. remove block group
		answer += result.cnt * result.cnt;

		for (pair<int, int>& r : result.blocks) {
			matrix[r.first][r.second] = DISABLE;
		}

		// 3. down
		down();

		// 4. roll
		roll();

		// 5. down
		down();
	}

	cout << answer << '\n';

	return 0;
}