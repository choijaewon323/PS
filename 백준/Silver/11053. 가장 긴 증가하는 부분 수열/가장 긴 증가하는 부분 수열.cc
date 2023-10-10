#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1000];
int cache[1001];
int lis3(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || arr[start] < arr[next]) {
			ret = max(ret, lis3(next) + 1);
		}
	}
	return ret;
}
int main() {
	for (int i = 0; i < 1000; i++) {
		cache[i] = -1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << lis3(-1) - 1 << '\n';
	return 0;
}