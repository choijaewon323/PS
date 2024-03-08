#include <iostream>
using namespace std;

#define MAX 100000
#define INF 1000000000

int N;
int dp[3];
int arr[MAX][3];
int di[] = { -1, 0, 1 };

int maxFunc(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int minFunc(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

bool inRange(int x) {
	if (0 <= x && x < 3) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> arr[y][x];
		}
	}

	dp[0] = arr[0][0];
	dp[1] = arr[0][1];
	dp[2] = arr[0][2];
	for (int y = 0; y < N - 1; y++) {
		int present[] = { dp[0], dp[1], dp[2] };
		for (int x = 0; x < 3; x++) {
			for (int i = 0; i < 3; i++) {
				int nextX = x + di[i];

				if (inRange(nextX)) {
					dp[nextX] = maxFunc(dp[nextX], present[x] + arr[y + 1][nextX]);
				}
			}
		}
	}

	int maxAns = -1;
	for (int x = 0; x < 3; x++) {
		maxAns = maxFunc(maxAns, dp[x]);
	}
	
	dp[0] = arr[0][0];
	dp[1] = arr[0][1];
	dp[2] = arr[0][2];
	for (int y = 0; y < N - 1; y++) {
		int present[] = { dp[0], dp[1], dp[2] };
		int next[] = { INF, INF, INF };
		for (int x = 0; x < 3; x++) {
			for (int i = 0; i < 3; i++) {
				int nextX = x + di[i];

				if (inRange(nextX)) {
					next[nextX] = minFunc(next[nextX], present[x] + arr[y + 1][nextX]);
				}
			}
		}
		for (int x = 0; x < 3; x++) {
			dp[x] = next[x];
		}
	}

	int minAns = INF;
	for (int x = 0; x < 3; x++) {
		minAns = minFunc(minAns, dp[x]);
	}

	cout << maxAns << " " << minAns << '\n';

	return 0;
}