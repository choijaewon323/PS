#include <iostream>
#include <vector>
using namespace std;
void func(int n, int m, vector<int>& numbers, int index) {
	if (index == m) {
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			for (auto num : numbers) {
				if (i == num) {
					flag = false;
					break;
				}
			}
			if (flag) {
				numbers.push_back(i);
				for (auto num : numbers) {
					cout << num << " ";
				}
				cout << '\n';
				numbers.pop_back();
			}
			flag = true;
		}
		return;
	}
	if (numbers.empty()) {
		for (int i = 1; i <= n; i++) {
			numbers.push_back(i);
			func(n, m, numbers, index + 1);
			numbers.pop_back();
		}
	}
	else {
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			for (auto num : numbers) {
				if (i == num) {
					flag = false;
					break;
				}
			}
			if (flag) {
				numbers.push_back(i);
				func(n, m, numbers, index + 1);
				numbers.pop_back();
			}
			flag = true;
		}
	}
}
int main() {
	int n, m;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> numbers;
	cin >> n >> m;
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cout << i << '\n';
		}
	} 
	else {
		func(n, m, numbers, 1);
	}
	return 0;
}