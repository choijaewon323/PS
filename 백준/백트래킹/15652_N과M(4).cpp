#include <iostream>
#include <vector>

using namespace std;

void func(int n, int m, vector<int>& seq, int index) {
	if (index == m) {
		if (seq.empty()) {
			for (int i = 1; i <= n; i++) {
				cout << i << '\n';
			}
			return;
		}
		int small = seq.back();
		for (int i = small; i <= n; i++) {
			seq.push_back(i);
			for (auto num : seq) {
				cout << num << " ";
			}
			cout << '\n';
			seq.pop_back();
		}
		return;
	}
	if (seq.empty()) {
		for (int i = 1; i <= n; i++) {
			seq.push_back(i);
			func(n, m, seq, index + 1);
			seq.pop_back();
		}
	}
	else {
		int small = seq.back();
		for (int i = small; i <= n; i++) {
			seq.push_back(i);
			func(n, m, seq, index + 1);
			seq.pop_back();
		}
	}
}

int main() {
	int n, m;
	vector<int> seq;
	cin >> n >> m;
	func(n, m, seq, 1);
	return 0;
}