#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	stack<char> bracket;
	stack<char> reverse;
	queue<char> result;
	getline(cin, s);

	for (auto i : s) {
		if (i == '<') {
			if (reverse.size() > 0) {
				while (!reverse.empty()) {
					// stack에서 꺼내서 queue로 
					char temp = reverse.top();
					reverse.pop();
					result.push(temp);
				}
				bracket.push(i);
				result.push(i);
			}
			else {
				bracket.push(i);
				result.push(i);
			}
		}

		if (i == '>') {
			bracket.pop();
			result.push(i);
		}

		if (i == ' ') {
			if (bracket.size() > 0) {
				result.push(i);
				continue;
			}
			if (reverse.size() > 0) {
				while (!reverse.empty()) {
					// stack에서 꺼내서 queue로
					char temp = reverse.top();
					reverse.pop();
					result.push(temp);
				}
				result.push(i);
			}
			else {
				result.push(i);
			}
		}

		if (i >= 'a' && i <= 'z' || i >= '0' && i <= '9') {
			if (bracket.size() > 0) {
				result.push(i);
			}
			else {
				reverse.push(i);
			}
		}
	}
	
	while (!reverse.empty()) {
		char temp = reverse.top();
		reverse.pop();
		result.push(temp);
	}

	while (!result.empty()) {
		char temp = result.front();
		result.pop();
		cout << temp;
	}

	cout << '\n';

	return 0;
}