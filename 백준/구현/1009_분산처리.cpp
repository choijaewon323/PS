#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		int temp = a;
		for (int j = 1; j <= b - 1; j++) {
			temp *= a;
			temp %= 10;
		}
		temp %= 10;
		if (temp == 0) {
			cout << 10 << '\n';
		}
		else {
			cout << temp << '\n';
		}
	}
	return 0;
}