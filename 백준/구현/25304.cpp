#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	int n;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		result += a * b;
	}
	if (result == x) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}
	return 0;
}