#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> numbers;
	for (int i = 0; i < 7; i++) {
		int num;
		cin >> num;
		if (num % 2 == 1) {
			numbers.push_back(num);
		}
	}
	if (numbers.empty()) {
		cout << -1 << '\n';
	}
	else {
		int sum = 0;
		for (auto i : numbers) {
			sum += i;
		}
		sort(numbers.begin(), numbers.end());
		cout << sum << '\n';
		cout << numbers.front() << '\n';
	}
	return 0;
}