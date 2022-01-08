#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> words;
bool sortByLength(string& left, string& right) {
	if (left.size() == right.size()) {
		return left < right;
	}
	else {
		return left.size() < right.size();
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
	sort(words.begin(), words.end(), sortByLength);
	string temp = "";
	for (auto i : words) {
		if (temp == i) {
			continue;
		}
		cout << i << '\n';
		temp = i;
	}
	return 0;
}