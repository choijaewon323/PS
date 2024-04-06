#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define UP 0
#define DOWN 1
#define FRONT 2
#define BACK 3
#define LEFT 4
#define RIGHT 5

typedef vector<vector<vector<char>>> V;

int n;
vector<string> commands;
V cube;

void init() {
	cube = V(6, vector<vector<char>>(3, vector<char>(3, 0)));
	commands.clear();
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cube[UP][y][x] = 'w';
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cube[DOWN][y][x] = 'y';
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cube[FRONT][y][x] = 'r';
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cube[BACK][y][x] = 'o';
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cube[LEFT][y][x] = 'g';
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cube[RIGHT][y][x] = 'b';
		}
	}
}

vector<vector<char>> rollPlane(vector<vector<char>>& temp, char direction) {
	vector<vector<char>> result = temp;
	if (direction == '+') {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				result[y][x] = temp[2-x][y];
			}
		}
	} else {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				result[y][x] = temp[x][2-y];
			}
		}
	}
	return result;
}

void up(char direction) {	/// clear
	V result = cube;
	vector<vector<char>> plane = rollPlane(cube[UP], direction);
	result[UP] = plane;
	if (direction == '+') {	// clock
		for (int i = 0; i < 3; i++) {
			result[RIGHT][0][i] = cube[BACK][0][i];
			result[FRONT][0][i] = cube[RIGHT][0][i];
			result[LEFT][0][i] = cube[FRONT][0][i];
			result[BACK][0][i] = cube[LEFT][0][i];
		}
	} else {	// counter clock
		for (int i = 0; i < 3; i++) {
			result[LEFT][0][i] = cube[BACK][0][i];
			result[FRONT][0][i] = cube[LEFT][0][i];
			result[RIGHT][0][i] = cube[FRONT][0][i];
			result[BACK][0][i] = cube[RIGHT][0][i];
		}
	}
	cube = result;
}

void down(char direction) {	// clear
	V result = cube;
	vector<vector<char>> plane = rollPlane(cube[DOWN], direction);
	result[DOWN] = plane;
	if (direction == '+') {	// clock
		for (int i = 0; i < 3; i++) {
			result[RIGHT][2][i] = cube[FRONT][2][i];
			result[BACK][2][i] = cube[RIGHT][2][i];
			result[LEFT][2][i] = cube[BACK][2][i];
			result[FRONT][2][i] = cube[LEFT][2][i];
		}
	} else {	// counter clock
		for (int i = 0; i < 3; i++) {
			result[LEFT][2][i] = cube[FRONT][2][i];
			result[BACK][2][i] = cube[LEFT][2][i];
			result[RIGHT][2][i] = cube[BACK][2][i];
			result[FRONT][2][i] = cube[RIGHT][2][i];
		}
	}
	cube = result;
}


void front(char direction) {	// clear
	V result = cube;
	vector<vector<char>> plane = rollPlane(cube[FRONT], direction);
	result[FRONT] = plane;
	if (direction == '+') {	// clock
		for (int i = 0; i < 3; i++) {
			result[RIGHT][i][0] = cube[UP][2][i];
			result[DOWN][0][2-i] = cube[RIGHT][i][0];
			result[LEFT][i][2] = cube[DOWN][0][i];
			result[UP][2][2-i] = cube[LEFT][i][2];
		}
	} else {	// counter clock
		for (int i = 0; i < 3; i++) {
			result[LEFT][2-i][2] = cube[UP][2][i];
			result[DOWN][0][i] = cube[LEFT][i][2];
			result[RIGHT][2-i][0] = cube[DOWN][0][i];
			result[UP][2][i] = cube[RIGHT][i][0];
		}
	}
	cube = result;
}

void back(char direction) {
	V result = cube;
	vector<vector<char>> plane = rollPlane(cube[BACK], direction);
	result[BACK] = plane;
	if (direction == '+') {	// clock
		for (int i = 0; i < 3; i++) {
			result[LEFT][2-i][0] = cube[UP][0][i];
			result[DOWN][2][i] = cube[LEFT][i][0];
			result[RIGHT][2-i][2] = cube[DOWN][2][i];
			result[UP][0][i] = cube[RIGHT][i][2];
		}
	} else {	// counter clock
		for (int i = 0; i < 3; i++) {
			result[RIGHT][i][2] = cube[UP][0][i];
			result[DOWN][2][2-i] = cube[RIGHT][i][2];
			result[LEFT][i][0] = cube[DOWN][2][i];
			result[UP][0][2-i] = cube[LEFT][i][0];
		}
	}
	cube = result;
}

void left(char direction) {	// clear
	V result = cube;
	vector<vector<char>> plane = rollPlane(cube[LEFT], direction);
	result[LEFT] = plane;
	if (direction == '+') {	// clock
		for (int i = 0; i < 3; i++) {
			result[FRONT][i][0] = cube[UP][i][0];
			result[DOWN][i][0] = cube[FRONT][i][0];
			result[BACK][2-i][2] = cube[DOWN][i][0];
			result[UP][2-i][0] = cube[BACK][i][2];
		}
	} else {	// counter clock
		for (int i = 0; i < 3; i++) {
			result[BACK][2-i][2] = cube[UP][i][0];
			result[DOWN][2-i][0] = cube[BACK][i][2];
			result[FRONT][i][0] = cube[DOWN][i][0];
			result[UP][i][0] = cube[FRONT][i][0];
		}
	}
	cube = result;
}

void right(char direction) {
	V result = cube;
	vector<vector<char>> plane = rollPlane(cube[RIGHT], direction);
	result[RIGHT] = plane;
	if (direction == '+') {	// clock
		for (int i = 0; i < 3; i++) {
			result[BACK][2-i][0] = cube[UP][i][2];
			result[DOWN][2-i][2] = cube[BACK][i][0];
			result[FRONT][i][2] = cube[DOWN][i][2];
			result[UP][i][2] = cube[FRONT][i][2];
		}
	} else {	// counter clock
		for (int i = 0; i < 3; i++) {
			result[FRONT][i][2] = cube[UP][i][2];
			result[DOWN][i][2] = cube[FRONT][i][2];
			result[BACK][2-i][0] = cube[DOWN][i][2];
			result[UP][2-i][2] = cube[BACK][i][0];
		}
	}
	cube = result;
}

void input() {
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		commands.push_back(cmd);
	}
}

void solve() {
	for (string& cmd : commands) {
		char plane = cmd[0];
		char direction = cmd[1];
		switch (plane) {
		case 'U':
			up(direction);
			break;
		case 'D':
			down(direction);
			break;
		case 'F':
			front(direction);
			break;
		case 'B':
			back(direction);
			break;
		case 'L':
			left(direction);
			break;
		case 'R':
			right(direction);
			break;
		}
	}
}

void output() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << cube[UP][y][x];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++) {
		input();
		solve();
		output();
	}
	return 0;
}