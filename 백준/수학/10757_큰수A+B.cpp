#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int tempA[10002];
int tempB[10002];
int answer[10002];
int main() {
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int index = 10001;
	for (auto i : a) {
		tempA[index] = i - '0';
		index--;
	}
	index = 10001;
	for (auto i : b) {
		tempB[index] = i - '0';
		index--;
	}
	for (int i = 10001; i >= 1; i--) {
		answer[i] = (tempA[i] + tempB[i]) % 10;
		tempA[i - 1] += (tempA[i] + tempB[i]) / 10;
	}
	bool flag = true;
	for (int i = 0; i <= 10001; i++) {
		if (answer[i] != 0) {
			flag = false;
		}
		if (flag) {
			continue;
		}
		cout << answer[i];
	}
	cout << '\n';
	return 0;
}