#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char board[51][51];
void swap(char& a, char& b) {
	char temp;
	temp = a;
	a = b;
	b = temp;
}
int maxCandy(int n) {
	int result = -1;
	for (int y = 1; y <= n; y++) {
		int temp = 1;
		vector<int> count;
		char tempCandy;
		for (int x = 1; x <= n; x++) {
			if (x == 1) {
				tempCandy = board[y][x];
				continue;
			}
			if (board[y][x] == tempCandy) {
				temp++;
			}
			else {
				tempCandy = board[y][x];
				count.push_back(temp);
				temp = 1;
			}
		}
		count.push_back(temp);
		sort(count.begin(), count.end());
		result = max(result, count.back());
	}
	for (int x = 1; x <= n; x++) {
		int temp = 1;
		vector<int> count;
		char tempCandy;
		for (int y = 1; y <= n; y++) {
			if (y == 1) {
				tempCandy = board[y][x];
				continue;
			}
			if (board[y][x] == tempCandy) {
				temp++;
			}
			else {
				tempCandy = board[y][x];
				count.push_back(temp);
				temp = 1;
			}
		}
		count.push_back(temp);
		sort(count.begin(), count.end());
		result = max(result, count.back());
	}
	return result;
}
int func(int n) {
	int result = -1;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (x == n && y == n) {
				break;
			}
			else if (x == n) {
				if (board[y][x] != board[y + 1][x]) {
					swap(board[y][x], board[y + 1][x]);
					result = max(result, maxCandy(n));
					swap(board[y][x], board[y + 1][x]);
				}
			}
			else if (y == n) {
				if (board[y][x] != board[y][x + 1]) {
					swap(board[y][x], board[y][x + 1]);
					result = max(result, maxCandy(n));
					swap(board[y][x], board[y][x + 1]);
				}
			}
			else {
				if (board[y][x] != board[y + 1][x]) {
					swap(board[y][x], board[y + 1][x]);
					result = max(result, maxCandy(n));
					swap(board[y][x], board[y + 1][x]);
				}
				if (board[y][x] != board[y][x + 1]) {
					swap(board[y][x], board[y][x + 1]);
					result = max(result, maxCandy(n));
					swap(board[y][x], board[y][x + 1]);
				}
			}
		}
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> board[y][x];
		}
	}
	cout << func(n) << '\n';
	return 0;
}