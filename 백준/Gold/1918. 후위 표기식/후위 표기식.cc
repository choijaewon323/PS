#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	stack<char> st;

	for (int i = 0; i < input.size(); i++) {
		char c = input[i];

		if ('A' <= c && c <= 'Z') {
			cout << c;
		} else {
			if (c == '(') {
				st.push(c);
			} else if (c == '*' || c == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top();
					st.pop();
				}
				st.push(c);
			} else if (c == '+' || c == '-') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.push(c);
			} else if (c == ')') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}