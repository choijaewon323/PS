#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	dp[n][k] : k개의 정수를 사용해서 그 합이 n이 되는 경우의 수

	dp[2][2] : 합이 2를 만드는데, 2개의 정수를 사용해서 만들려면 어떠헥?
		: 1 + 1, 2 + 0
		: 
*/

int dp[201][201];
int N, K;

int solve(int num, int cnt) {
	if (cnt == K) {
		if (num == 0) {
			return 1;
		}
		return 0;
	}

	if (dp[num][cnt] != -1) {
		return dp[num][cnt];
	}

	int result = 0;
	for (int i = 0; i <= N; i++) {
		if (num - i >= 0) {
			result += solve(num - i, cnt + 1);
			result %= 1000000000;
		}
	}
	return dp[num][cnt] = result;
}

void init() {
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			dp[i][j] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	init();
	
	cout << solve(N, 0) << '\n';

	return 0;
}