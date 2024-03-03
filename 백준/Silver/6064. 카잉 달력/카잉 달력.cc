#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

void solve() {
	int M, N, x, y;
	int cnt = 1, sx = 1, sy = 1;
	
	cin >> M >> N >> x >> y;
	
	int maxNum = lcm(M, N);
	for (; x <= maxNum; x += M) {
		if ((x - 1) % N + 1 == y || x > maxNum) {
			break;
		}
	}

	if (x > maxNum) {
		cout << -1 << "\n";
	} else {
		cout << x << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		solve();
	}

	return 0;
}