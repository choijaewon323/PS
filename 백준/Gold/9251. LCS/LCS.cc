#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 1000
#define MAX 1000

int dp[MAX + 1][MAX + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	int aSize = a.size();
	int bSize = b.size();

	for (int i = 0; i <= aSize; i++) {
		for (int j = 0; j <= bSize; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int result = 0;
	for (int i = 0; i <= aSize; i++) {
		for (int j = 0; j <= bSize; j++) {
			result = max(result, dp[i][j]);
		}
	}
	cout << result << '\n';

	return 0;
}