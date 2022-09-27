#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int blank = n - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= blank; j++) {
			cout << " ";
		}
		blank--;
		if (blank == -1) {
			for (int j = 1; j <= i * 2 - 1; j++) {
				cout << "*";
			}
		}
		else {
			for (int j = 1; j <= i; j++) {
				if (i == j) {
					cout << "*";
				}
				else if (j == 1) {
					cout << "* ";
				}
				else {
					cout << "  ";
				}
			}
		}
		cout << '\n';
	}

	return 0;
}