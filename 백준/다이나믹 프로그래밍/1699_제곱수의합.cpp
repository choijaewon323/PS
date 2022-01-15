#include <iostream>
#include <algorithm>
using namespace std;
int cache[100001];
int func(int n) {
	if (n == 0) {
		return 0;
	}
	int& ret = cache[n];
	if (ret != 0) {
		return ret;
	}
	int result = INT16_MAX;
	for (int i = 1; i * i <= n; i++) {
		ret = 1 + func(n - i * i);
		result = min(result, ret);
	}
	return ret = result;
}
int main() {
	int n;
	cin >> n;
	cout << func(n) << '\n';
	return 0;
}