#include <iostream>
#include <string>
using namespace std;
char board[8][8];
int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> board[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i <= 6; i += 2) {
		for (int j = 0; j <= 6; j += 2) {
			if (board[i][j] == 'F') {
				result++;
			}
		}
	}
	for (int i = 1; i <= 7; i += 2) {
		for (int j = 1; j <= 7; j += 2) {
			if (board[i][j] == 'F') {
				result++;
			}
		}
	}
	cout << result << '\n';
	return 0;
}