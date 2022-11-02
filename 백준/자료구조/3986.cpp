#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string& word) {
	stack<char> st;
	char temp;
	
	if (word.size() % 2 != 0) {
		return false;
	}

	for (auto w : word) {
		if (st.empty()) {
			st.push(w);
		}
		else {
			temp = st.top();
			if (temp == w) {
				st.pop();
			}
			else {
				st.push(w);
			}
		}
	}

	if (st.size() > 0) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string word;
	int n, count;
	bool isAIn, isBIn;
	cin >> n;

	count = 0;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (check(word)) {
			count++;
		}
	}
	cout << count << '\n';

	return 0;
}