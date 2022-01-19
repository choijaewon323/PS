#include <iostream>
using namespace std;
int cache[1000001];
int func(int num) {
	if (num == 1) {
		return 1;
	}
	if (num == 2) {
		return 2;
	}
	if (num == 3) {
		return 4;
	}
	if (cache[num] != -1) {
		return cache[num];
	}
	int result = 0;
	for (int i = 1; i <= 3; i++) {
		if (num - i >= 1) {
			cache[num - i] = func(num - i) % 1000000009;
			result += cache[num - i];
			result %= 1000000009;
		}
	}
	return cache[num] = result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	for (int i = 0; i < 1000001; i++) {
		cache[i] = -1;
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << func(n) << '\n';
	}
	return 0;
}