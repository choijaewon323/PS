#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> numbers;
bool func(int num, int start, int end) {
	int index = (start + end) / 2;
	if (numbers[index] == num) {
		return true;
	}
	if (index == start || index == end) {
		if (numbers[index + 1] == num) {
			return true;
		}
		else {
			return false;
		}
	}
	if (numbers[index] > num) {
		return func(num, start, index);
	}
	if (numbers[index] < num) {
		return func(num, index, end);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		cout << func(temp, 0, numbers.size() - 1) << '\n';
	}
	return 0;
}