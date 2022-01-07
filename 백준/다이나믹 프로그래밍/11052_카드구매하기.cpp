#include <iostream>
#include <algorithm>
using namespace std;
int p[1001];
int dp[1001];
int func(int n) {
	if (n == 0) {
		return 0;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, p[i] + func(n - i));
	}
	return dp[n] = result;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	cout << func(n) << '\n';
	return 0;
}