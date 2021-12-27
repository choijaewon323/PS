#include <iostream>
#include <vector>
using namespace std;
void func(int n, int m, vector<int>& seq, int index) {
	if (index == m) {
		int temp = seq.back();
		for (int i = temp + 1; i <= n; i++) {
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
		int temp = seq.back();
		for (int i = temp + 1; i <= n; i++) {
			seq.push_back(i);
			func(n, m, seq, index + 1);
			seq.pop_back();
		}
	}
}
int main() {
	int n, m;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> seq;
	cin >> n >> m;
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cout << i << '\n';
		}
	}
	else {
		func(n, m, seq, 1);
	}
	return 0;
}