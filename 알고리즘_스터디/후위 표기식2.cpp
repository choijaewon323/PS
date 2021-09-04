#include <iostream>
#include <string>
using namespace std;

#define MAX 100

double alphabet[26];

class stack {
private:
	double arr[MAX] = {0};
	int index = 0;

public:
	void push(double element) {
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

	double top() {
		if(index == 0) return -1;
		return arr[index - 1];
	}
};

int main() {
	stack st;

	int n;
	cin >> n;

	string str;
	cin >> str;
	
	for(int i = 0; i < n; i++) {
		cin >> alphabet[i];
	}

	for(int i = 0; i < str.size(); i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') st.push(alphabet[str[i] - 'A']);
		else {
			double n1, n2;

			n2 = st.top();
			st.pop();
			n1 = st.top();
			st.pop();

			switch(str[i]) {
				case '+': n1 = n1 + n2; break;
				case '-': n1 = n1 - n2; break;
				case '*': n1 = n1 * n2; break;
				case '/': n1 = n1 / n2; break;
			}
			st.push(n1);
		}
	}

	printf("%.2lf\n", st.top());

	return 0;
}