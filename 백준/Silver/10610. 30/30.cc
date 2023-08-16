#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string input;

	cin >> input;

	bool flag = false;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '0') {
			flag = true;
			break;
		}
	}

	if (!flag) {
		cout << -1 << '\n';

		return 0;
	}

	int acc = 0;

	for (int i = 0; i < input.size(); i++) {
		acc += input[i] - '0';
	}

	if (acc % 3 == 0) {
		// possible
		sort(input.begin(), input.end(), greater<char>());

		cout << input << '\n';
	}
	else {
		// impossible
		cout << -1 << '\n';
	}

	return 0;
}