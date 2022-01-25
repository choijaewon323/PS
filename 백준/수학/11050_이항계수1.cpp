#include <iostream>
using namespace std;
int bino(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	return bino(n - 1, r - 1) + bino(n - 1, r);
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << bino(n, k) << '\n';
	return 0;
}