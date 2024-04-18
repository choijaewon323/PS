#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 16
#define INF 1000000000

int N;
int W[MAX][MAX];
bool visited[MAX];
int dp[1000000][16];
int endState;

int solve(int state, int here) {
	if (state == endState) {
		if (W[here][0]) {
			return W[here][0];
		} else {
			return INF;
		}
	}

	if (dp[state][here] != -1) {
		return dp[state][here];
	}

	int result = INF;
	for (int i = 0; i < N; i++) {
		int next = state & (1 << i);

		if (!next && W[here][i]) {
			state ^= (1 << i);
			result = min(result, solve(state, i) + W[here][i]);
			state ^= (1 << i);
		}
	}

	return dp[state][here] = result;
}

void init() {
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 16; j++) {
			dp[i][j] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> N;

	endState = (1 << N) - 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> W[y][x];
		}
	}

	int state = 0;
	state ^= 1;
	int answer = solve(state, 0);

	cout << answer << '\n';

	return 0;
}