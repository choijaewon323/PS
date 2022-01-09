#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void func(int n, int m, vector<int>& seq, vector<int>& index) {
	if (m == index.size()) {
		for (auto i : index) {
			cout << seq[i] << " ";
		}
		cout << '\n';
		return;
	}
	if (index.empty()) {
		for (int i = 0; i < n; i++) {
			index.push_back(i);
			func(n, m, seq, index);
			index.pop_back();
		}
		return;
	}
	for (int i = index.back(); i < n; i++) {
		index.push_back(i);
		func(n, m, seq, index);
		index.pop_back();
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