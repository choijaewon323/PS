#include <iostream>
using namespace std;
bool sq[10001];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= 100; i++) {
		sq[i * i] = true;
	}
	int minimun = 0;
	int result = 0;
	for (int num = m; num <= n; num++) {
		if (!minimun && sq[num]) {
			minimun = num;
			result += num;
		}
		else if (sq[num]) {
			result += num;
		}
	}
	if (!minimun) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n' << minimun << '\n';
	}
	return 0;
}