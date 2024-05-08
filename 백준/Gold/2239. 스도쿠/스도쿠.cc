#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define SIZE 9

int board[SIZE][SIZE];

void input() {
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			char c;
			cin >> c;

			board[y][x] = c - '0';
		}
	}
}

pair<int, int> findStart(int y, int x) {
	y /= 3;
	x /= 3;
	y *= 3;
	x *= 3;

	return { y, x };
}

pair<int, int> nextPos(int y, int x) {
	x++;
	if (x == SIZE) {
		x = 0;
		y++;
	}

	return { y, x };
}

vector<int> candidate(int y, int x) {
	vector<bool> check(10, false);

	for (int i = 0; i < SIZE; i++) {
		int numberX = board[y][i];
		int numberY = board[i][x];
		
		check[numberX] = true;
		check[numberY] = true;
	}

	pair<int, int> start = findStart(y, x);
	for (int i = start.first; i < start.first + 3; i++) {
		for (int j = start.second; j < start.second + 3; j++) {
			int number = board[i][j];

			check[number] = true;
		}
	}

	vector<int> results;
	for (int i = 1; i <= 9; i++) {
		if (!check[i]) {
			results.push_back(i);
		}
	}
	return results;
}

void print() {
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			cout << board[y][x];
		}
		cout << '\n';
	}
	cout << '\n';
}

bool solve(int y, int x) {
	if (y == SIZE) {
		print();

		return true;
	}
	if (board[y][x] != 0) {
		pair<int, int> next = nextPos(y, x);
		
		bool result = solve(next.first, next.second);
		if (result) {
			return true;
		}
		return false;
	}

	vector<int> cand = candidate(y, x);
	for (int c : cand) {
		board[y][x] = c;
		pair<int, int> next = nextPos(y, x);
		bool result = solve(next.first, next.second);
		if (result) {
			return true;
		}
		board[y][x] = 0;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve(0, 0);

	return 0;
}