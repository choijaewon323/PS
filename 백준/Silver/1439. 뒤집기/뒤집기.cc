#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;

	cin >> input;

	if (input.size() == 1) {
		cout << 0 << '\n';
		return 0;
	}

	int zero = 0;
	int one = 0;
	bool zeroFlag = false;
	bool oneFlag = false;

	if (input[0] == '0') {
		zeroFlag = true;
	}
	else {
		oneFlag = true;
	}

	for (int i = 1; i < input.size(); i++) {
		if (input[i] == '0') {
			if (oneFlag) {
				oneFlag = false;
				one++;
				zeroFlag = true;
			}
		}
		else {
			if (zeroFlag) {
				zeroFlag = false;
				zero++;
				oneFlag = true;
			}
		}
	}

	if (zeroFlag) {
		zero++;
	}
	if (oneFlag) {
		one++;
	}

	int answer = min(zero, one);

	cout << answer << '\n';

	return 0;
}