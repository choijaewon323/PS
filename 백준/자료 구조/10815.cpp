#include <iostream>
using namespace std;

bool arr[20000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[temp + 10000000] = true;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		cout << arr[temp + 10000000] << '\n';
	}

	return 0;
}