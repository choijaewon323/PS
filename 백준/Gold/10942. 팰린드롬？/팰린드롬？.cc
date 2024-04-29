#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 2000

int N, M;
int arr[MAX + 1];
bool dp[MAX + 1][MAX + 1];

bool inRange(int x) {
	if (1 <= x && x <= N) {
		return true;
	}
	return false;
}

void solve() {

	for (int dist = 1; dist <= N; dist++) {
		for (int i = 1; i <= N; i++) {
			int start = i;
			int end = start + dist - 1;

			if (inRange(end)) {
				if (dist == 1) {
					dp[start][end] = true;
				} else if (dist == 2) {
					if (arr[start] == arr[end]) {
						dp[start][end] = true;
					}
				} else {
					int innerStart = start + 1;
					int innerEnd = end - 1;
					
					if (dp[innerStart][innerEnd] && arr[start] == arr[end]) {
						dp[start][end] = true;
					}
				}
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	solve();

	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;

		if (dp[S][E]) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}