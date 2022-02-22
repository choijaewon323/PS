#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<vector<char>> board(5, vector<char>(15, '?'));
	for (int i = 0; i < 5; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			board[i][j] = temp[j];
		}
	}
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 5; y++) {
			if (board[y][x] != '?') {
				cout << board[y][x];
			}
		}
	}
	cout << '\n';
	return 0;
}