#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
using namespace std;

/*
	한번의 이동은 전체 블록을 상하좌우 중 하나로 이동시킴
	같은 값을 갖는 두 블록 충돌 시 하나로 합쳐짐
	한번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 합쳐질 수 없음

*/

int N;

vector<vector<int>> up(vector<vector<int>> board) {
	for (int x = 0; x < N; x++) {
		vector<int> temp;
		for (int y = 0; y < N; y++) {
			if (board[y][x] == 0) {
				continue;
			}

			temp.push_back(board[y][x]);
		}

		stack<pair<int, bool>> st;
		for (int t : temp) {
			if (st.empty()) {
				st.push({ t, false });
			} else {
				if (st.top().first == t) {
					if (st.top().second == false) {
						st.pop();
						st.push({ t + t, true });
					} else {
						st.push({ t, false });
					}
				} else {
					st.push({ t, false });
				}
			}
		}
		vector<int> result;
		while (!st.empty()) {
			result.push_back(st.top().first);
			st.pop();
		}

		reverse(result.begin(), result.end());

		for (int y = 0; y < result.size(); y++) {
			board[y][x] = result[y];
		}
		for (int y = result.size(); y < N; y++) {
			board[y][x] = 0;
		}
	}

	return board;
}

vector<vector<int>> down(vector<vector<int>> board) {
	for (int x = 0; x < N; x++) {
		vector<int> temp;
		for (int y = N - 1; y >= 0; y--) {
			if (board[y][x] == 0) {
				continue;
			}

			temp.push_back(board[y][x]);
		}

		stack<pair<int, bool>> st;
		for (int t : temp) {
			if (st.empty()) {
				st.push({ t, false });
			} else {
				if (st.top().first == t) {
					if (st.top().second == false) {
						st.pop();
						st.push({ t + t, true });
					} else {
						st.push({ t, false });
					}
				} else {
					st.push({ t, false });
				}
			}
		}
		vector<int> result;
		while (!st.empty()) {
			result.push_back(st.top().first);
			st.pop();
		}

		reverse(result.begin(), result.end());

		int index = 0;
		for (int y = N - 1; y >= 0; y--) {
			if (index == result.size()) {
				board[y][x] = 0;
			} else {
				board[y][x] = result[index++];
			}
		}
	}

	return board;
}

vector<vector<int>> left(vector<vector<int>> board) {
	for (int y = 0; y < N; y++) {
		vector<int> temp;
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 0) {
				continue;
			}

			temp.push_back(board[y][x]);
		}

		stack<pair<int, bool>> st;
		for (int t : temp) {
			if (st.empty()) {
				st.push({ t, false });
			} else {
				if (st.top().first == t) {
					if (st.top().second == false) {
						st.pop();
						st.push({ t + t, true });
					} else {
						st.push({ t, false });
					}
				} else {
					st.push({ t, false });
				}
			}
		}
		vector<int> result;
		while (!st.empty()) {
			result.push_back(st.top().first);
			st.pop();
		}

		reverse(result.begin(), result.end());

		for (int x = 0; x < N; x++) {
			if (x >= result.size()) {
				board[y][x] = 0;
			} else {
				board[y][x] = result[x];
			}
		}
	}

	return board;
}

vector<vector<int>> right(vector<vector<int>> board) {
	for (int y = 0; y < N; y++) {
		vector<int> temp;
		for (int x = N - 1; x >= 0; x--) {
			if (board[y][x] == 0) {
				continue;
			}

			temp.push_back(board[y][x]);
		}

		stack<pair<int, bool>> st;
		for (int t : temp) {
			if (st.empty()) {
				st.push({ t, false });
			} else {
				if (st.top().first == t) {
					if (st.top().second == false) {
						st.pop();
						st.push({ t + t, true });
					} else {
						st.push({ t, false });
					}
				} else {
					st.push({ t, false });
				}
			}
		}
		vector<int> result;
		while (!st.empty()) {
			result.push_back(st.top().first);
			st.pop();
		}

		reverse(result.begin(), result.end());

		int index = 0;
		for (int x = N - 1; x >= 0; x--) {
			if (index == result.size()) {
				board[y][x] = 0;
			} else {
				board[y][x] = result[index++];
			}
		}
	}

	return board;
}

int findLargest(vector<vector<int>> board) {
	int result = -1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			result = max(result, board[y][x]);
		}
	}
	return result;
}

int solve(vector<vector<int>> board, int cnt) {
	if (cnt == 5) {
		return findLargest(board);
	}

	int result = -1;
	
	vector<vector<int>> upRes = up(board);
	result = max(result, solve(upRes, cnt + 1));

	vector<vector<int>> downRes = down(board);
	result = max(result, solve(downRes, cnt + 1));

	vector<vector<int>> leftRes = left(board);
	result = max(result, solve(leftRes, cnt + 1));

	vector<vector<int>> rightRes = right(board);
	result = max(result, solve(rightRes, cnt + 1));

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<vector<int>> board = vector<vector<int>>(N, vector<int>(N, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}

	int answer = solve(board, 0);
	cout << answer << '\n';
	
	return 0;
}