#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define MAX 100

int N, L;
int matrix[MAX][MAX];

int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	
	return num;
}

bool rowCheck(int y) {
	vector<bool> applied(N, false);
	
	for (int x = 0; x < N; x++) {
		if (x == N - 1) {
			continue;
		}

		int present = matrix[y][x];
		int next = matrix[y][x + 1];

		if (absolute(present - next) >= 2) {
			return false;
		}

		if (present == next) {
			continue;
		
		} else if (present < next) {
			int startX = x;
			int endX = x - L + 1;
			if (endX < 0) {
				return false;
			}

			for (int i = startX; i >= endX; i--) {
				if (applied[i]) {
					return false;
				}

				if (present != matrix[y][i]) {
					return false;
				}

				applied[i] = true;
			}
		
		} else {	// present > next
			int startX = x + 1;
			int endX = x + L;
			
			if (endX >= N) {
				return false;
			}

			for (int i = startX; i <= endX; i++) {
				if (applied[i]) {
					return false;
				}

				if (next != matrix[y][i]) {
					return false;
				}

				applied[i] = true;
			}
		}
	}

	return true;
}

bool columnCheck(int x) {
	vector<bool> applied(N, false);

	for (int y = 0; y < N; y++) {
		if (y == N - 1) {
			continue;
		}

		int present = matrix[y][x];
		int next = matrix[y + 1][x];

		if (absolute(present - next) >= 2) {
			return false;
		}

		if (present == next) {
			continue;

		} else if (present < next) {
			int startY = y;
			int endY = y - L + 1;
			if (endY < 0) {
				return false;
			}

			for (int i = startY; i >= endY; i--) {
				if (applied[i]) {
					return false;
				}

				if (present != matrix[i][x]) {
					return false;
				}

				applied[i] = true;
			}

		} else {	// present > next
			int startY = y + 1;
			int endY = y + L;

			if (endY >= N) {
				return false;
			}

			for (int i = startY; i <= endY; i++) {
				if (applied[i]) {
					return false;
				}

				if (next != matrix[i][x]) {
					return false;
				}

				applied[i] = true;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
		}
	}

	int answer = 0;

	// row check
	for (int y = 0; y < N; y++) {
		if (rowCheck(y)) {
			answer++;
		}
	}

	// column check
	for (int x = 0; x < N; x++) {
		if (columnCheck(x)) {
			answer++;
		}
	}

	cout << answer << '\n';

	return 0;
}