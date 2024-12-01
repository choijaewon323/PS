#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

#define MAX 5000
#define MOD 1000000

string word;
int dp[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = -1;
	}
}

int solve(int index) {
	if (index == word.size()) {
		return 1;
	}

	if (dp[index] != -1) {
		return dp[index];
	}

	int result = 0;

	// 1. one word
	char c = word[index];
	
	if (c == '0') {
		return 0;
	}
	
	result += solve(index + 1);
	result %= MOD;
	
	// 2. two word
	if (index <= word.size() - 2) {
		string temp = "";
		temp += c;
		temp += word[index + 1];

		int num = stoi(temp);

		if (10 <= num && num <= 26) {
			result += solve(index + 2);
			result %= MOD;
		}
	}

	return dp[index] = result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> word;

	init();

	cout << solve(0) << '\n';

	return 0;
}