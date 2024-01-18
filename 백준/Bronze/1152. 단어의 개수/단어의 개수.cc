#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input, char delimit) {
	stringstream ss(input);
	string temp;
	vector<string> results;

	while (getline(ss, temp, delimit)) {
		results.push_back(temp);
	}

	return results;
}

bool isBlank(string& str) {
	if (str.empty()) {
		return true;
	}

	for (char c : str) {
		if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z') {
			continue;
		}
		return true;
	}

	return false;
}

int main() {
	string input;

	getline(cin, input);

	vector<string> splited = split(input, ' ');

	int answer = 0;
	for (string &str : splited) {
		if (!isBlank(str)) {
			answer++;
		}
	}

	cout << answer << '\n';

	return 0;
}