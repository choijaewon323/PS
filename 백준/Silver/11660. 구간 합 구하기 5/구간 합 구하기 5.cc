#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 1024

int N, M;

int sumArr[MAX + 1][MAX + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int temp;
			cin >> temp;

			sumArr[y][x] = sumArr[y - 1][x] + sumArr[y][x - 1] - sumArr[y - 1][x - 1]
				+ temp;
		}
	}

	for (int i = 0; i < M; i++) {
		int y1, x1, y2, x2;

		cin >> y1 >> x1 >> y2 >> x2;
		
		int result = sumArr[y2][x2] - sumArr[y2][x1 - 1] - sumArr[y1 - 1][x2]
			+ sumArr[y1 - 1][x1 - 1];
		cout << result << '\n';
	}

	return 0;
}