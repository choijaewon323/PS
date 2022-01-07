#include <iostream>
#include <algorithm>
using namespace std;
int things[100][2];
int n;
int dp[100001][100];
int func(int restWeight, int index) {
	if (dp[restWeight][index] != -1) {
		return dp[restWeight][index];
	}
	int result = 0;
	for (int i = index + 1; i < n; i++) {
		if (things[i][0] <= restWeight) {
			result = max(result, things[i][1] + func(restWeight - things[i][0], i));
		}
	}
	return dp[restWeight][index] = result;
}
int main() {
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> things[i][0] >> things[i][1];
	}
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 100; j++) {
			dp[i][j] = -1;
		}
	}
	cout << func(k, -1) << '\n';
	return 0;
}