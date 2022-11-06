#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	stack<char> st;
	string bracket;
	int result = 0;
	cin >> bracket;
	for (int i = 0; i < bracket.size(); i++) {
		if (bracket[i] == '(') {
			st.push('(');
		}
		else {	// ')' ÀÏ °æ¿ì
			if (bracket[i - 1] == '(') {
				st.pop();
				result += st.size();
			}
			else if (bracket[i - 1] == ')') {
				st.pop();
				result++;
			}
		}
	}
	cout << result << '\n';
	return 0;
}