#include <iostream>
#include <math.h>
using namespace std;
int square(int num) {
	return num * num;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, y1, x2, y2;
		double r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double d = sqrt(square(abs(x2 - x1)) + square(abs(y2 - y1)));
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << '\n';
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2) {
			cout << 0 << '\n';
		}
		else if (abs(r2 - r1) < d && d < r2 + r1) {
			cout << 2 << '\n';
		}
		else if (r2 + r1 == d || abs(r2 - r1) == d) {
			cout << 1 << '\n';
		}
		else if (r2 + r1 < d || d < abs(r2 - r1)) {
			cout << 0 << '\n';
		}
	}
	return 0;
}