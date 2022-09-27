#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int blank = n - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < blank; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			if (j == i) {
				cout << "*";
			}
			else {
				cout << "* ";
			}
		}
		blank--;
		cout << '\n';
	}

	return 0;
}