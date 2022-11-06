#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	int n;
	map<string, int> m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		if (m.find(temp) == m.end()) {
			m[temp] = 1;
		}
		else {
			m[temp]++;
		}
	}

	vector<pair<string, int>> srt;

	for (auto temp : m) {
		srt.push_back(temp);
	}

	sort(srt.begin(), srt.end(), compare);

	cout << srt.front().first << '\n';

	return 0;
}