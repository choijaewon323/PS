#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.second == right.second) {
		return left.first < right.first;
	}
	return left.second < right.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	vector<pair<int, int>> location;
	cin >> n;
	for (int i = 0; i < n; i++)	{
		int x, y;
		cin >> x >> y;
		location.push_back(make_pair(x, y));
	}
	sort(location.begin(), location.end(), compare);
	for (auto i : location) {
		cout << i.first << " " << i.second << '\n';
	}
	return 0;
}