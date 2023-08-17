#include <iostream>

using namespace std;

int main() {
	int T;

	cin >> T;

	for (int test = 0; test < T; test++) {
		int C;

		cin >> C;

		int q = 0, d = 0, n = 0, p = 0;

		while (C > 0) {
			if (C >= 25) {
				C -= 25;
				q++;
			}
			else if (C >= 10) {
				C -= 10;
				d++;
			}
			else if (C >= 5) {
				C -= 5;
				n++;
			}
			else {
				C--;
				p++;
			}
		}

		cout << q << " " << d << " " << n << " " << p << '\n';
	}

	return 0;
}