#include <iostream>
#include <vector>
using namespace std;
void func(vector<int>& s, int prevIndex, vector<int>& seq) {
	if (prevIndex == -1) {
		for (int index = 0; index < s.size(); index++) {
			seq.push_back(index);
			func(s, index, seq);
			seq.pop_back();
		}
		return;
	}
	if (seq.size() == 6) {
		for (auto num : seq) {
			cout << s[num] << " ";
		}
		cout << '\n';
		return;
	}
	for (int index = prevIndex + 1; index < s.size(); index++) {
		seq.push_back(index);
		func(s, index, seq);
		seq.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int k;
	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}
		vector<int> s;
		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			s.push_back(temp);
		}
		vector<int> seq;
		func(s, -1, seq);
		cout << '\n';
	}
	return 0;
}