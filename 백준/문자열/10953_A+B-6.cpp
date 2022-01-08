#include <iostream>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string temp;
		cin >> temp;
		cout << (temp[0] - '0') + (temp[2] - '0') << '\n';
	}
	return 0;
}