#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> numbers;

void func(string& number) {
	if (number.size() >= 9) {
		return;
	}
	int length = number.size();
	number += '4';
	numbers.push_back(number);
	func(number);
	number = number.substr(0, length);
	number += '7';
	numbers.push_back(number);
	func(number);
}

int main() {
	int a, b;
	int answer = 0;
	string number = "";
	cin >> a >> b;

	func(number);

	for (auto i : numbers) {
		int temp = stoi(i);
		if (temp >= a && temp <= b) {
			answer++;
		}
	}

	cout << answer << '\n';

	return 0;
}