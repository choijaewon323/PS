#include <iostream>
#include <vector>
using namespace std;
void func(int n, int m, vector<int>& seq, int index) {
	if (m == index) {
		for (int i = 1; i <= n; i++) {
			seq.push_back(i);
			for (auto num : seq) {
				cout << num << " ";
			}
			cout << '\n';
			seq.pop_back();
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		seq.push_back(i);
		func(n, m, seq, index + 1);
		seq.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	vector<int> seq;
	cin >> n >> m;
	func(n, m, seq, 1);
	return 0;
}