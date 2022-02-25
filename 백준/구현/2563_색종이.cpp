#include <iostream>
using namespace std;

bool plane[100][100];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = 99 - y; j > (99 - y) - 10; j--) {
			for (int k = x; k < x + 10; k++) {
				plane[j][k] = true;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (plane[i][j]) {
				result++;
			}
		}
	}

	cout << result << '\n';

	return 0;
}