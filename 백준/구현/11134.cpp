#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, c;
		cin >> n >> c;

		int days = 0;
		while (1) {
			days++;
			n -= c;
			if (n <= 0) {
				break;
			}
		}
		cout << days << '\n';
	}

	return 0;
}