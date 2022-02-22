#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	vector<string> names;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		names.push_back(temp);
	}
	if (n == 1) {
		cout << names.front() << '\n';
	}
	else {
		string answer = "";
		for (int i = 0; i < names.front().size(); i++) {
			bool flag = true;
			for (int j = 1; j < names.size(); j++) {
				if (names[j][i] != names[j - 1][i]) {
					flag = false;
					answer += '?';
					break;
				}
			}
			if (flag) {
				answer += names[0][i];
			}
		}
		cout << answer << '\n';
	}
	return 0;
}