#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string t;
	while (true) {
		cin >> t;
		if (t == "0") {
			break;
		}
		string temp = t;
		int num1 = stoi(t);
		reverse(temp.begin(), temp.end());
		int num2 = stoi(temp);
		if (num1 == num2) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
	return 0;
}