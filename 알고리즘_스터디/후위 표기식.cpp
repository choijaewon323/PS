#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class stack {
private:
	char arr[MAX] = {0};
	int index = 0;

public:
	void push(char element) {
		if(index == MAX) return;

		arr[index++] = element;
	}
	
	void pop() {
		if(index == 0) return;

		index--;
	}

	bool empty() {
		if(index == 0) return true;
		else return false;
	}

	char top() {
		if(index == 0) return -1;
		return arr[index - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	stack st;

	cin >> str;

	for(int i = 0; i < str.size(); i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') cout << str[i];

		switch(str[i]) {
			case '(':
				st.push(str[i]);
				break;

			case ')':
				while(!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}

				st.pop();
				break;

			case '*':
			case '/':
				while(!st.empty() && (st.top() != '+' && st.top() != '-' && st.top() != '(')) {
					cout << st.top();
					st.pop();
				}

				st.push(str[i]);
				break;

			case '+':
			case '-':
				while(!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}

				st.push(str[i]);
				break;
		}
	}

	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}