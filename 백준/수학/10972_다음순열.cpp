#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	vector<int> per;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		per.push_back(temp);
	}
	bool result = next_permutation(per.begin(), per.end());
	if (result) {
		for (auto i : per) {
			cout << i << " ";
		}
		cout << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}