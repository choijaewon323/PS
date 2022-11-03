#include <iostream>
using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, temp, acc, i, j;
	cin >> n >> m;
	acc = 0;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		acc += temp;
		arr[i] = acc;
	}

	for (int index = 0; index < m; index++) {
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << '\n';
	}


	return 0;
}