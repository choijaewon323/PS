#include <iostream>
#include <string>
#include <map>

using namespace std;

char toUpper(char c) {
	return (char)((c - 'a') + 'A');
}

int main() {
	string word;
	cin >> word;
	map<char, int> cnt;
	for (char c : word) {
		if ('a' <= c && c <= 'z') {
			c = toUpper(c);
		}
		cnt[c]++;
	}

	char result = '\0';
	int tempCnt = 0;
	for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
		char c = iter->first;
		int presentCnt = iter->second;

		if (presentCnt > tempCnt) {
			tempCnt = presentCnt;
			result = c;
		}
	}

	for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
		char c = iter->first;
		int presentCnt = iter->second;

		if (presentCnt == tempCnt && c != result) {
			result = '?';
		}
	}

	cout << result << '\n';

	return 0;
}