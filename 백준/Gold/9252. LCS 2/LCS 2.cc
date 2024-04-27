#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

int dp[MAX + 1][MAX + 1];
string a, b;

string print(int i, int j) {
	if (i == 0 || j == 0) {
		return "";
	} else if (a[i - 1] == b[j - 1]) {
		return print(i - 1, j - 1) + a[i - 1];
	}

	if (dp[i][j - 1] >= dp[i - 1][j]) {
		return print(i, j - 1);
	} else {
		return print(i - 1, j);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a;
	cin >> b;
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
	cout << dp[aSize][bSize] << '\n';
	cout << print(aSize, bSize) << '\n';

	return 0;
}