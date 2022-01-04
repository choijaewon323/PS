#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void func(int l, vector<char>& givenAlphabet, vector<char>& answer) {
	if (l == answer.size()) {
		int vowel = 0;
		int consonant = 0;
		for (auto index : answer) {
			if (givenAlphabet[index] == 'a' || givenAlphabet[index] == 'e' 
				|| givenAlphabet[index] == 'i' || givenAlphabet[index] == 'o' 
				|| givenAlphabet[index] == 'u') {
				vowel++;
			}
			else {
				consonant++;
			}
		}
		if (vowel >= 1 && consonant >= 2) {
			for (auto index : answer) {
				cout << givenAlphabet[index];
			}
			cout << '\n';
		}
	}
	if (answer.empty()) {
		for (int i = 0; i < givenAlphabet.size(); i++) {
			answer.push_back(i);
			func(l, givenAlphabet, answer);
			answer.pop_back();
		}
	}
	else {
		for (int i = answer.back() + 1; i < givenAlphabet.size(); i++) {
			answer.push_back(i);
			func(l, givenAlphabet, answer);
			answer.pop_back();
		}
	}
}
int main() {
	int l, c;
	vector<char> givenAlphabet;
	vector<char> answer;
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char temp;
		cin >> temp;
		givenAlphabet.push_back(temp);
	}
	sort(givenAlphabet.begin(), givenAlphabet.end());
	func(l, givenAlphabet, answer);
	return 0;
}