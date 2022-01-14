#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool compare1(pair<int, pair<int, int>>& left,
	pair<int, pair<int, int>>& right) {
	return left.second.first < right.second.first;
}
bool compare2(pair<int, pair<int, int>>& left,
	pair<int, pair<int, int>>& right) {
	return left.first < right.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	vector<pair<int, pair<int, int>>> input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input.push_back(make_pair(i, make_pair(x, -1)));
	}
	sort(input.begin(), input.end(), compare1);
	int index = 0;
	int temp = input.front().second.first;
	for (auto& i : input) {
		if (temp == i.second.first) {
			i.second.second = index;
			continue;
		}
		index++;
		temp = i.second.first;
		i.second.second = index;
	}
	sort(input.begin(), input.end(), compare2);
	for (auto& i : input) {
		cout << i.second.second << " ";
	}
	cout << '\n';
	return 0;
}