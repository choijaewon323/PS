#include <iostream>
using namespace std;
int dp[100001];
int main() {
	int n;
	cin >> n;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	int answer = dp[n];
	for (int i = n - 1; i >= 1; i--) {
		answer += dp[i];
		answer %= 9901;
	}
	cout << (answer + 1) % 9901 << '\n';
	return 0;
}