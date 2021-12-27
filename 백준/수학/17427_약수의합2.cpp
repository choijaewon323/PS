#include <iostream>
using namespace std;
int main() {
	int n;
	long long result = 0;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		result += i * (n / i);
	}
	cout << result << '\n';
	return 0;
}