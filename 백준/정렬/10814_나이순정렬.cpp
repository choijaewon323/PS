#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;
bool compare(pair<int, pair<int, string>>& left, 
	pair<int, pair<int, string>>& right) {
	if (left.second.first == right.second.first) {
		return left.first < right.first;
	}
	return left.second.first < right.second.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<pair<int, pair<int, string>>> members;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		members.push_back(make_pair(i, make_pair(age, name)));
	}
	sort(members.begin(), members.end(), compare);
	for (auto i : members) {
		cout << i.second.first << " " << i.second.second << '\n';
	}
	return 0;
}