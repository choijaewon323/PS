#include <iostream>
#include <iostream>
#include <vector>
using namespace std;
int arr[9];
void func(vector<int>& seq) {
	if (seq.size() == 7) {
		int result = 0;
		for (auto i : seq) {
			result += arr[i];
		}
		if (result == 100) {
			for (auto i : seq) {
				cout << arr[i] << '\n';
			}
		}
		return;
	}
	if (seq.empty()) {
		for (int i = 0; i < 9; i++) {
			seq.push_back(i);
			func(seq);
			seq.pop_back();
		}
	}
	else {
		for (int i = seq.back() + 1; i < 9; i++) {
			seq.push_back(i);
			func(seq);
			seq.pop_back();
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	vector<int> seq;
	func(seq);
	return 0;
}