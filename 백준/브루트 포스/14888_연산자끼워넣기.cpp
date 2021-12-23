#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int funcMax(int n, vector<int>& numbers, vector<int>& operators,
	int index, int left, int right) {
	int result = -1000000001;

	if (index + 1 == n) {
		if (operators[0]) {
			return left + right;
		}
		if (operators[1]) {
			return left - right;
		}
		if (operators[2]) {
			return left * right;
		}
		if (operators[3]) {
			return left / right;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] != 0) {
			operators[i]--;
			
			if (i == 0) {
				result = max(result, funcMax(n, numbers, operators,
					index + 1, left + right, numbers[index + 1]
				));
			}
			if (i == 1) {
				result = max(result, funcMax(n, numbers, operators,
					index + 1, left - right, numbers[index + 1]
				));
			}
			if (i == 2) {
				result = max(result, funcMax(n, numbers, operators,
					index + 1, left * right, numbers[index + 1]
				));
			}
			if (i == 3) {
				result = max(result, funcMax(n, numbers, operators,
					index + 1, left / right, numbers[index + 1]
				));
			}
			
			operators[i]++;
		}
	}
	
	return result;
}

int funcMin(int n, vector<int>& numbers, vector<int>& operators,
	int index, int left, int right) {
	int result = 1000000001;

	if (index + 1 == n) {
		if (operators[0]) {
			return left + right;
		}
		if (operators[1]) {
			return left - right;
		}
		if (operators[2]) {
			return left * right;
		}
		if (operators[3]) {
			return left / right;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] != 0) {
			operators[i]--;

			if (i == 0) {
				result = min(result, funcMin(n, numbers, operators,
					index + 1, left + right, numbers[index + 1]
				));
			}
			if (i == 1) {
				result = min(result, funcMin(n, numbers, operators,
					index + 1, left - right, numbers[index + 1]
				));
			}
			if (i == 2) {
				result = min(result, funcMin(n, numbers, operators,
					index + 1, left * right, numbers[index + 1]
				));
			}
			if (i == 3) {
				result = min(result, funcMin(n, numbers, operators,
					index + 1, left / right, numbers[index + 1]
				));
			}

			operators[i]++;
		}
	}

	return result;
}

int main() {
	int n;
	vector<int> numbers, operators;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		numbers.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		int oper;
		cin >> oper;

		operators.push_back(oper);
	}

	cout << funcMax(n, numbers, operators, 1, numbers[0], numbers[1]) << '\n'
		<< funcMin(n, numbers, operators, 1, numbers[0], numbers[1]) << '\n';
	
	return 0;
}