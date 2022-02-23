#include <string>
#include <iostream>
using namespace std;
int main() {
	string input;
	string answer = "";
	cin >> input;
	for (auto i : input) {
		if (i >= 'A' && i <= 'Z') {
			answer += i;
		}
	}
	cout << answer << '\n';
	return 0;
}