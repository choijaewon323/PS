#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> divisor;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			divisor.push_back(i);
		}
	}
	sort(divisor.begin(), divisor.end());
	if (k > divisor.size()) {
		cout << 0 << '\n';
	}
	else {
		cout << divisor[k - 1] << '\n';
	}
	return 0;
}