#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string input;
	cin >> input;
	input += '/';
	vector<string> split;
	string temp = "";
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			temp += input[i];
		}
		else if (input[i] == '+' || input[i] == '-') {
			split.push_back(temp);
			temp = "";
			temp += input[i];
			split.push_back(temp);
			temp = "";
		}
		else {
			split.push_back(temp);
		}
	}
	vector<int> answers;
	int num = 0;
	for (int i = 0; i < split.size(); i++) {
		if (split[i] == "-") {
			answers.push_back(num);
			num = 0;
		}
		if (i % 2 == 0) {
			num += stoi(split[i]);
		}
	}
	answers.push_back(num);
	if (answers.size() == 1) {
		cout << answers.front() << '\n';
	}
	else {
		int result = answers.front();
		for (int i = 1; i < answers.size(); i++) {
			result -= answers[i];
		}
		cout << result << '\n';
	}
	return 0;
}