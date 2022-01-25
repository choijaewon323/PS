#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string sentence;
	while (true) {
		stack<char> st;
		getline(cin, sentence, '.');
		cin.ignore();
		if (sentence.empty()) {
			break;
		}
		bool flag = true;
		for (auto ch : sentence) {
			if (ch == '(') {
				st.push('(');
			}
			else if (ch == '[') {
				st.push('[');
			}
			else if (ch == ')') {
				if (st.empty()) {
					cout << "no" << '\n';
					flag = false;
					break;
				}
				else if (st.top() == '(') {
					st.pop();
				}
				else {
					cout << "no" << '\n';
					flag = false;
					break;
				}
			}
			else if (ch == ']') {
				if (st.empty()) {
					cout << "no" << '\n';
					flag = false;
					break;
				}
				else if (st.top() == '[') {
					st.pop();
				}
				else {
					cout << "no" << '\n';
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			if (st.empty()) {
				cout << "yes" << '\n';
			}
			else {
				cout << "no" << '\n';
			}
		}
		sentence.clear();
	}
	return 0;
}