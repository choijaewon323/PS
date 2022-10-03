#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	map<int, int> card;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		card[temp]++;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		cout << card[temp] << '\n';
	}

	return 0;
}