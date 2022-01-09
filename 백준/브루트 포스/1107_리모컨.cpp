#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isBreak[10];
int main() {
	int n;
	cin >> n;
	int m;
	int result = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		isBreak[temp] = true;
	}
	int interval = (n - 100) > 0 ? (n - 100) : -(n - 100);
	int result1 = (n - 100) > 0 ? (n - 100) : -(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		string temp = to_string(i);
		bool flag = true;
		for (auto digit : temp) {
			if (isBreak[digit - '0']) {
				flag = false;
			}
		}
		if (flag) {
		int num = (n - i) > 0 ? (n - i) : -(n - i);
			if (interval > num) {
				interval = num;
				result = temp.size();
			}
		}
	}
	result += interval;
	cout << min(result, result1) << '\n';
	return 0;
}