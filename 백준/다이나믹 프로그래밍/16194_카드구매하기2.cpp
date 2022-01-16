#include <iostream>
using namespace std;
int dp[1001];
int p[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	dp[1] = p[1];
	dp[2] = min(p[1] + p[1], p[2]);
	for (int i = 3; i <= n; i++) {
		int temp = p[i];
		for (int j = 1; j <= i - 1; j++) {
			temp = min(temp, dp[i - j] + p[j]);
		}
		dp[i] = temp;
	}
	cout << dp[n] << '\n';
	return 0;
}