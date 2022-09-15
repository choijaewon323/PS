#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int y = 0; y < n; y++) {
		int temp = n - y - 1;


		for (int x = 0; x < n * 2 - 1; x++) {
			if (x < temp) {
				cout << " ";
			}
			else if (x >= temp && x < temp + (2 * y + 1)) {
				cout << "*";
			}
			else if (x >= temp + (2 * y + 1)) {
				break;
			}
		}
		cout << '\n';
	}

	return 0;
}