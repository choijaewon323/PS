#include <iostream>
using namespace std;
int n;
int k;
int cache[201][201];
int func(int tempN, int tempK) {
	if (tempK == k) {
		return 1;
	}
	if (cache[tempN][tempK] != -1) {
		return cache[tempN][tempK];
	}
	int result = 0;
	for (int i = tempN; i >= 0; i--) {
		cache[tempN - i][tempK + 1] = func(tempN - i, tempK + 1) % 1000000000;
		result += cache[tempN - i][tempK + 1];
		result %= 1000000000;
	}
	return cache[tempN][tempK] = result;
}
int main() {
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			cache[i][j] = -1;
		}
	}
	cin >> n >> k;
	cout << func(n, 1) << '\n';
	return 0;
}