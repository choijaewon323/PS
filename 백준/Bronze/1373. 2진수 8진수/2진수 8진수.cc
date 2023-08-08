#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

char convert(string binary) {
	char result;

	if (binary == "000") {
		result = '0';
	}
	else if (binary == "001") {
		result = '1';
	}
	else if (binary == "010") {
		result = '2';
	}
	else if (binary == "011") {
		result = '3';
	}
	else if (binary == "100") {
		result = '4';
	}
	else if (binary == "101") {
		result = '5';
	}
	else if (binary == "110") {
		result = '6';
	}
	else {
		result = '7';
	}

	return result;
}

int main() {
	string input;

	cin >> input;

	int binarySize = input.size();
	
	if (binarySize < 3) {
		if (input == "0") {
			cout << 0 << '\n';
		}
		else if (input == "1") {
			cout << 1 << '\n';
		}
		else if (input == "10") {
			cout << 2 << '\n';
		}
		else if (input == "11") {
			cout << 3 << '\n';
		}

		return 0;
	}

	int rest = binarySize % 3;

	string temp = "";
	for (int i = 0; i < (3 - rest) % 3; i++) {
		temp += '0';
	}
	input = temp + input;

	string result = "";
	for (int i = 0; i < input.size(); i += 3) {
		string sub = input.substr(i, 3);

		result += convert(sub);
	}

	cout << result << '\n';

	return 0;
}