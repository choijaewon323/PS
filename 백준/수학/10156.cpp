#include <iostream>
using namespace std;

int main() {
	int k, n, m;
	cin >> k >> n >> m;

	int result = k * n - m;

	if (result <= 0) {
		cout << 0 << '\n';
	}
	else {
		cout << result << '\n';
	}

	return 0;
}