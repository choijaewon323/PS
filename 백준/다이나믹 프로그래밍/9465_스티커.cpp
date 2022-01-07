#include <iostream>
#include <algorithm>
using namespace std;
int sticker[3][100001];
int dp[3][100001];
int n;
int func(int y, int x) {
	if (x == n) {
		return sticker[y][x];
	}
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	int result = 0;
	if (y == 1) {
		result = max(result, sticker[y][x] + func(2, x + 1));
	}
	else if (y == 2) {
		result = max(result, sticker[y][x] + func(1, x + 1));
	}
	if (x + 2 <= n) {
		result = max(result, sticker[y][x] + func(1, x + 2));
		result = max(result, sticker[y][x] + func(2, x + 2));
	}
	return dp[y][x] = result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int y = 1; y <= 2; y++){
			for (int x = 1; x <= n; x++) {
				cin >> sticker[y][x];
				dp[y][x] = -1;
			}
		}
		cout << max(func(1, 1), func(2, 1)) << '\n';
	}
	return 0;
}