#include <iostream>

using namespace std;

int main() {
	unsigned int S;

	cin >> S;

	int cnt = 0;
	long long acc = 0;
	for (cnt = 1; cnt <= 100000; cnt++) {
		acc += cnt;

		if (acc > S) {
			break;
		}
	}

	cout << cnt - 1 << '\n';

	return 0;
}