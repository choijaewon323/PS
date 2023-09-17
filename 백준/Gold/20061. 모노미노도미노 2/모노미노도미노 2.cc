#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

/*
	x가 행, y가 열
	블록은 1x1, 1x2, 2x1 세가지
	블록 놓을 위치를 빨간색 보드에서 선택하면, 파란색과 초록색으로 쭉 이동(경계 만나거나
	다른 블록 만날때까지)
	초록색 보드에서 행이 타일로 가득 차있다면 그 행의 타일은 모두 사라짐
	사라진 이후에는 초록 보드에서 사라진 행 위의 블록이 사라진 행 수 만큼 아래로 이동
	파란 보드의 경우는 열이 타일로 가득 차있다면 그 열의 타일이 모두 사라짐
	사라진 이후 사라진 열수만큼 오른쪽 이동

	한 행이나 열이 타일로 가득차 사라지면 1점 획득

	연한 색으로 되어있는 경우는 맨 오른쪽/맨 아래쪽 행/열이 사라짐

	만약 행/열이 가득찬 경우와 연한칸에 블록이 있는 경우 동시 발생
	-> 행/열 가득찬거 없애는게 먼저, 모두 수행된 뒤 연한 칸 처리

	블록은 보드에 놓인 이후에 다른 블록과 합쳐지지 않음
	
	결과 : 얻은 점수, 초록색 보드와 파란색 보드에 타일이 있는 칸의 개수

	t = 2 : 1 x 2 블록을 y, x / y, x + 1에 놓기
	t = 3 : 2 x 1 블록을 y, x / y + 1, x에 놓기

	블록 차지 칸이 빨간색 칸의 경계를 넘어가는 경우는 없음

	---- 알고리즘 구상 ---

	move의 경우 1x1은 문제없음
	1x2의 경우 blue의 경우 y, x + 1 을 먼저 보냄 - 그 위에 연쇄적으로 쌓으면 됨
				green의 경우 y,x 와 y,x+1을 보내봄 -> 둘중 레드에 가까운 쪽 기준으로 행/열 맞춤

	2x1의 경우 반대로

	move 함수의 경우 좌표 리턴 -> 한 점이 최종적으로 가능한 위치 리턴 - 내부에서 배열을 수정하지 않는 방식

	1. move
	2. delete (blue, green), moveRight, moveDown
	3. delete (light blue, light green), moveRight, moveDown

	moveRight, moveDown이 제일 중요함 - 가장 바깥쪽으로 밀어주는 함수

	
*/

#define BLUE 0
#define GREEN 1

vector<vector<bool>> blue(4, vector<bool>(6, false));
vector<vector<bool>> green(6, vector<bool>(4, false));

pair<int, int> move(int index, int color) {
	int y = 0, x = 0;

	switch (color) {
	case BLUE:	// 오른쪽 이동, index는 행의 위치
		while (x < 6) {
			if (blue[index][x]) {
				break;
			}
			x++;
		}
		x--;
		y = index;
		break;
	case GREEN:	// 아랫쪽 이동
		while (y < 6) {
			if (green[y][index]) {
				break;
			}
			y++;
		}
		y--;
		x = index;
	}

	return { y, x };
}

void moveRight() {

	vector<vector<bool>> temp(4, vector<bool>(6, false));

	int index = 5;

	for (int x = 5; x >= 0; x--) {
		// check
		bool flag = true;

		for (int y = 0; y < 4; y++) {
			if (blue[y][x]) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			for (int y = 0; y < 4; y++) {
				temp[y][index] = blue[y][x];
			}
			index--;
		}
	}

	blue = temp;
}

void moveDown() {
	vector<vector<bool>> temp(6, vector<bool>(4, false));
	int index = 5;

	for (int y = 5; y >= 0; y--) {
		// check
		bool flag = true;

		for (int x = 0; x < 4; x++) {
			if (green[y][x]) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			for (int x = 0; x < 4; x++) {
				temp[index][x] = green[y][x];
			}
			index--;
		}
	}
	
	green = temp;
}

int deleteBlue() {
	int result = 0;

	for (int x = 2; x < 6; x++) {
		bool flag = true;

		for (int y = 0; y < 4; y++) {
			if (!blue[y][x]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			result++;
			for (int y = 0; y < 4; y++) {
				blue[y][x] = false;
			}
		}
	}

	moveRight();

	return result;
}

int deleteGreen() {
	int result = 0;

	for (int y = 2; y < 6; y++) {
		bool flag = true;

		for (int x = 0; x < 4; x++) {
			if (!green[y][x]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			result++;
			for (int x = 0; x < 4; x++) {
				green[y][x] = false;
			}
		}
	}

	moveDown();
	return result;
}

void deleteLightBlue() {
	int cnt = 0;
	
	for (int x = 0; x < 2; x++) {
		bool flag = true;

		for (int y = 0; y < 4; y++) {
			if (blue[y][x]) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			cnt++;
		}
	}

	if (cnt == 2) {
		for (int x = 4; x < 6; x++) {
			for (int y = 0; y < 4; y++) {
				blue[y][x] = false;
			}
		}
	}
	else if (cnt == 1) {
		for (int y = 0; y < 4; y++) {
			blue[y][5] = false;
		}
	}

	moveRight();
}

void deleteLightGreen() {
	int cnt = 0;

	for (int y = 0; y < 2; y++) {
		bool flag = true;

		for (int x = 0; x < 4; x++) {
			if (green[y][x]) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			cnt++;
		}
	}

	if (cnt == 2) {
		for (int y = 4; y < 6; y++) {
			for (int x = 0; x < 4; x++) {
				green[y][x] = false;
			}
		}
	}
	else if (cnt == 1) {
		for (int x = 0; x < 4; x++) {
			green[5][x] = false;
		}
	}

	moveDown();
}

void printBlue() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 6; x++) {
			cout << blue[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void printGreen() {
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 4; x++) {
			cout << green[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	int score = 0;
	int cnt = 0;

	for (int line = 0; line < N; line++) {
		int t, y, x;

		cin >> t >> y >> x;

		if (t == 1) {	// 1 x 1
			// 1-1. move to blue
			pair<int, int> nextBlue = move(y, BLUE);
			blue[nextBlue.first][nextBlue.second] = true;

			// 1-2. move to green
			pair<int, int> nextGreen = move(x, GREEN);
			green[nextGreen.first][nextGreen.second] = true;
		}
		else if (t == 2) {	// 1 x 2
			// 1-1. move to blue
			pair<int, int> nextBlue = move(y, BLUE);
			blue[nextBlue.first][nextBlue.second] = true;
			nextBlue = move(y, BLUE);
			blue[nextBlue.first][nextBlue.second] = true;

			// 1-2. move to green
			pair<int, int> green1 = move(x, GREEN);
			pair<int, int> green2 = move(x + 1, GREEN);
			int minY = min(green1.first, green2.first);
			green[minY][x] = true;
			green[minY][x + 1] = true;
		}
		else {	// 2 x 1
			// 1-1. move to blue
			pair<int, int> blue1 = move(y, BLUE);
			pair<int, int> blue2 = move(y + 1, BLUE);
			int minX = min(blue1.second, blue2.second);
			blue[y][minX] = true;
			blue[y + 1][minX] = true;

			// 1-2. move to green
			pair<int, int> nextGreen = move(x, GREEN);
			green[nextGreen.first][nextGreen.second] = true;
			nextGreen = move(x, GREEN);
			green[nextGreen.first][nextGreen.second] = true;
		}

		// 2. deleteBlue and deleteGreen
		score += deleteBlue();
		score += deleteGreen();

		deleteLightBlue();
		deleteLightGreen();
	}

	// blue
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 6; x++) {
			if (blue[y][x]) {
				cnt++;
			}
		}
	}

	// green
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 4; x++) {
			if (green[y][x]) {
				cnt++;
			}
		}
	}

	cout << score << '\n';
	cout << cnt << '\n';

	return 0;
}