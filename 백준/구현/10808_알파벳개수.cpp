#include <iostream>
#include <string>
using namespace std;
int alpha[26];
int main() {
	string s;
	cin >> s;
	for (auto i : s) {
		alpha[i - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " ";
	}
	cout << '\n';
	return 0;
}