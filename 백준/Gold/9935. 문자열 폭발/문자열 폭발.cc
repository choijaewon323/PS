#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	string exp;

	cin >> input;
	cin >> exp;

	stack<pair<char, int>> st;
	
	int size = input.size();
	int expSize = exp.size();

	for (int i = 0; i < size; i++) {
		char c = input[i];

		if (st.empty()) {
			if (exp[0] == c) {
				st.push({ c, 1 });
			}
			else {
				st.push({ c, -1 });
			}
		}
		else {
			if (st.top().second == -1) {
				if (exp[0] == c) {
					st.push({ c, 1 });
				}
				else {
					st.push({ c, -1 });
				}
			}
			else {
				if (exp[st.top().second] == c) {
					st.push({ c, st.top().second + 1 });
				}
				else if (exp[0] == c) {
					st.push({ c, 1 });
				}
				else {
					st.push({ c, -1 });
				}
			}
		}

		if (st.top().second == expSize) {
			for (int j = 0; j < expSize; j++) {
				st.pop();
			}
		}
	}

	if (st.empty()) {
		cout << "FRULA" << '\n';
	}
	else {
		string result = "";

		while (!st.empty()) {
			result += st.top().first;
			st.pop();
		}

		reverse(result.begin(), result.end());

		cout << result << '\n';
	}

	return 0;
}