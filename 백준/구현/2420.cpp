#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long n, m;
	cin >> n >> m;

	n = (-n);
	long result = abs(m + n);
	cout << result << '\n';

	return 0;
}