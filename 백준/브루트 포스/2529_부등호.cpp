#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool digits[10];
vector<string> answers;
void func(vector<char>& signs, vector<int>& seq, int signIndex) {
	if (signs.size() == seq.size() - 1) {
		string temp = "";
		for (auto i : seq) {
			temp += to_string(i);
		}
		answers.push_back(temp);
		return;
	}
	if (seq.empty()) {
		for (int i = 0; i <= 9; i++) {
			digits[i] = true;
			seq.push_back(i);
			func(signs, seq, signIndex);
			digits[i] = false;
			seq.pop_back();
		}
		return;
	}
	int temp = seq.back();
	if (signs[signIndex] == '>') {
		for (int i = temp - 1; i >= 0; i--) {
			if (!digits[i]) {
				digits[i] = true;
				seq.push_back(i);
				func(signs, seq, signIndex + 1);
				digits[i] = false;
				seq.pop_back();
			}
		}
	}
	else {
		for (int i = temp + 1; i <= 9; i++) {
			if (!digits[i]) {
				digits[i] = true;
				seq.push_back(i);
				func(signs, seq, signIndex + 1);
				digits[i] = false;
				seq.pop_back();
			}
		}
	}
}
int main() {
	int k;
	vector<char> signs;
	vector<int> seq;
	cin >> k;
	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		signs.push_back(temp);
	}
	func(signs, seq, 0);
	sort(answers.begin(), answers.end());
	cout << answers.back() << '\n';
	cout << answers.front() << '\n';
	return 0;
}