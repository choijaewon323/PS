#include <iostream>
#include <algorithm>
using namespace std;

int basket[102];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= 101; i++) {
		basket[i] = i;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;

		reverse(basket + i, basket + 1 + j);

	}

	for (int i = 1; i <= n; i++) {
		cout << basket[i] << " ";
	}
	cout << '\n';

	return 0;
}