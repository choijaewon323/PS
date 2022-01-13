#include <iostream>
#include <vector>
using namespace std;
char s[11][11];
vector<int> answer;
bool isCorrect(int n, vector<int>& seq) {
	for (int i = 1; i < seq.size(); i++) {
		int temp = 0;
		for (int j = i; j < seq.size(); j++) {
			temp += seq[j];
			if (s[i][j] == '-' && temp >= 0) {
				return false;
			}
			if (s[i][j] == '0' && temp != 0) {
				return false;
			}
			if (s[i][j] == '+' && temp <= 0) {
				return false;
			}
		}
	}
	return true;
}
bool func(int n, vector<int>& seq, int index) {
	if (seq.size() == n + 1) {
		for (int i = 1; i < seq.size(); i++) {
			answer.push_back(seq[i]);
		}
		return true;
	}
	bool result = false;
	if (s[index][index] == '+') {
		for (int i = 1; i <= 10; i++) {
			bool temp;
			seq.push_back(i);
			temp = isCorrect(n, seq);
			if (temp) {
				result = func(n, seq, index + 1);
			}
			seq.pop_back();
			if (result) {
				return true;
			}
		}
	}
	else if (s[index][index] == '-') {
		for (int i = -10; i <= -1; i++) {
			bool temp;
			seq.push_back(i);
			temp = isCorrect(n, seq);
			if (temp) {
				result = func(n, seq, index + 1);
			}
			seq.pop_back();
			if (result) {
				return true;
			}
		}
	}
	else {
		bool temp;
		seq.push_back(0);
		temp = isCorrect(n, seq);
		if (temp) {
			result = func(n, seq, index + 1);
		}
		seq.pop_back();
		if (result) {
			return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> seq;
	seq.push_back(-11);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	func(n, seq, 1);
	for (auto i : answer) {
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}