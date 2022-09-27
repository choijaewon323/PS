#include <iostream>
using namespace std;

int basket[101];

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100; i++) {
		basket[i] = i;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		swap(basket[i], basket[j]);
	}

	for (int i = 1; i <= n; i++) {
		cout << basket[i] << " ";
	}
	cout << '\n';

	return 0;
}