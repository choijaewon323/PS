#include <iostream>
#include <stack>
#include <list>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<char> left;
	list<char> right;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		left.push(str[i]);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char command;
		cin >> command;
		switch (command) {
		case 'L':
			if (!left.empty()) {
				char temp = left.top();
				left.pop();
				right.push_front(temp);
			}
			break;
		case 'D':
			if (!right.empty()) {
				char temp = right.front();
				right.pop_front();
				left.push(temp);
			}
			break;
		case 'B':
			if (!left.empty()) {
				left.pop();
			}
			break;
		case 'P':
			char temp;
			cin >> temp;
			left.push(temp);
		}
	}
	stack<char> temp;
	while (!left.empty()) {
		char c = left.top();
		left.pop();
		temp.push(c);
	}
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
	for (auto i : right) {
		cout << i;
	}
	cout << '\n';
	return 0;
}