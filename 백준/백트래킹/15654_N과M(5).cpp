#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void func(int n, int m, vector<int>& seq, vector<int>& index) {
	if (index.size() == m) {
		for (auto i : index) {
			cout << seq[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (index.empty()) {
		for (int i = 0; i < seq.size(); i++) {
			index.push_back(i);
			func(n, m, seq, index);
			index.pop_back();
		}
		return;
	}
	for (int i = 0; i < seq.size(); i++) {
		bool flag = true;
		for (auto in : index) {
			if (in == i) {
				flag = false;
				break;
			}
		}
		if (flag) {
			index.push_back(i);
			func(n, m, seq, index);
			index.pop_back();
		}
	}
}
int main() {
	int n, m;
	vector<int> seq;
	vector<int> index;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		seq.push_back(temp);
	}
	sort(seq.begin(), seq.end());
	func(n, m, seq, index);
	return 0;
}