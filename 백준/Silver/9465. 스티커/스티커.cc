#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 100000

int n;
int sticker[2][MAX];
int dp[2][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		cin >> n;
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < n; x++) {
				cin >> sticker[y][x];
			}
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[0][1] + sticker[1][0];
		dp[1][1] = sticker[1][1] + sticker[0][0];

		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], 
				max(dp[0][i - 2], dp[1][i - 2])) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 1], 
				max(dp[0][i - 2], dp[1][i - 2])) + sticker[1][i];
		}

		int result = -1;
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < n; x++) {
				result = max(result, dp[y][x]);
			}
		}
		cout << result << '\n';
	}
	

	return 0;
}