#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int64_t, int64_t>& a, pair<int64_t, int64_t> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	map<int64_t, int64_t> m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int64_t temp;
		cin >> temp;
		m[temp]++;
	}

	vector<pair<int64_t, int64_t>> result(m.begin(), m.end());

	sort(result.begin(), result.end(), compare);

	cout << result.front().first << '\n';
	return 0;
}