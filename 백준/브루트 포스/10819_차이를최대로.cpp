#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector<int> seq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		seq.push_back(temp);
	}
	sort(seq.begin(), seq.end());
	int result = 0;
	for (int i = 0; i < seq.size() - 1; i++) {
		int temp = seq[i] - seq[i + 1];
		temp = temp > 0 ? temp : -temp;
		result += temp;
	}
	while (next_permutation(seq.begin(), seq.end())) {
		int temp = 0;
		for (int i = 0; i < seq.size() - 1; i++) {
			int t = seq[i] - seq[i + 1];
			t = t > 0 ? t : -t;
			temp += t;
		}
		result = max(temp, result);
	}
	cout << result << '\n';
	return 0;
}