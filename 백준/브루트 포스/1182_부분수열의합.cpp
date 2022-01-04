#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sequence[20];
int func(int n, int s, int subSize, vector<int>& subseq) {
	if (subSize == subseq.size()) {
		int sum = 0;
		for (auto i : subseq) {
			sum += sequence[i];
		}
		if (sum == s) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (subseq.empty()) {
		int result = 0;
		for (int i = 0; i < n; i++) {
			subseq.push_back(i);
			result += func(n, s, subSize, subseq);
			subseq.pop_back();
		}
		return result;
	}
	else {
		int result = 0;
		for (int i = subseq.back() + 1; i < n; i++) {
			subseq.push_back(i);
			result += func(n, s, subSize, subseq);
			subseq.pop_back();
		}
		return result;
	}
}
int main() {
	int n, s, result = 0;
	vector<int> subseq;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}
	for (int i = 1; i <= n; i++) {
		result += func(n, s, i, subseq);
	}
	cout << result << '\n';
	return 0;
}