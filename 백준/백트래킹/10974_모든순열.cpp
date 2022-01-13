#include <iostream>
#include <vector>
using namespace std;
bool isUsed[9];
void per(int n, vector<int>& seq) {
	if (seq.size() == n) {
		for (auto i : seq) {
			cout << i << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (!isUsed[i]) {
			seq.push_back(i);
			isUsed[i] = true;
			per(n, seq);
			seq.pop_back();
			isUsed[i] = false;
		}
	}
}
int main() {
	int n;
	vector<int> seq;
	cin >> n;
	per(n, seq);
	return 0;
}