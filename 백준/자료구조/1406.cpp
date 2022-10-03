#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	deque<char> left;
	deque<char> right;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		left.push_back(str[i]);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char command;
		cin >> command;
		switch (command) {
		case 'L':
			if (!left.empty()) {
				char temp = left.back();
				left.pop_back();
				right.push_front(temp);
			}
			break;
		case 'D':
			if (!right.empty()) {
				char temp = right.front();
				right.pop_front();
				left.push_back(temp);
			}
			break;
		case 'B':
			if (!left.empty()) {
				left.pop_back();
			}
			break;
		case 'P':
			char temp;
			cin >> temp;
			left.push_back(temp);
		}
	}
	for (auto i : left) {
		cout << i;
	}
	for (auto i : right) {
		cout << i;
	}
	cout << '\n';
	return 0;
}