#include <iostream>
using namespace std;
int cache[100001][4];
int func(int n, int prev) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	if (cache[n][prev] != -1) {
		return cache[n][prev];
	}
	int result = 0;
	for (int i = 1; i <= 3; i++) {
		if (i == prev) {
			continue;
		}
		cache[n - i][i] = func(n - i, i) % 1000000009;
		result += cache[n - i][i];
		result %= 1000000009;
	}
	return cache[n][prev] = result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 4; j++) {
			cache[i][j] = -1;
		}
	}
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			cout << 0 << '\n';
			continue;
		}
		cout << func(n, 0) << '\n';
	}
	return 0;
}