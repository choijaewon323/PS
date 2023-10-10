#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int func(string& s1, string& s2, int index1, int index2) {
	if (dp[index1][index2] != -1) {
		return dp[index1][index2];
	}
	if (s1.size() == index1 || s2.size() == index2) {
		return 0;
	}
	if (s1[index1] == s2[index2]) {
		return dp[index1][index2] = 1 + func(s1, s2, index1 + 1, index2 + 1);
	}
	return dp[index1][index2] = max(func(s1, s2, index1 + 1, index2), func(s1, s2, index1, index2 + 1));
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
	string s1, s2;
	cin >> s1 >> s2;
	cout << func(s1, s2, 0, 0) << '\n';
	return 0;
}