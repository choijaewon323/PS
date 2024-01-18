#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> cnt;
vector<string> words;

bool compare(string &a, string &b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		if (cnt[temp] == 0) {
			cnt[temp] = 1;
		}
	}

	for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
		words.push_back(iter->first);
	}

	sort(words.begin(), words.end(), compare);

	for (string& word : words) {
		cout << word << '\n';
	}

	return 0;
}