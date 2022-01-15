#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		int num = gcd(a, b);
		cout << a * b / num << '\n';
	}
	return 0;
}