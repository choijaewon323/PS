#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout.precision(9);
	cout << fixed;
	cout << (double) a / (double) b << '\n';
	return 0;
}