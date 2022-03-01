#include <iostream>
using namespace std;

int cup[4];

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int m;
	cin >> m;

	cup[1] = 1;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		swap(cup[a], cup[b]);
	}

	for (int i = 1; i <= 3; i++) {
		if (cup[i] == 1) {
			cout << i << '\n';
		}
	}

	return 0;
}