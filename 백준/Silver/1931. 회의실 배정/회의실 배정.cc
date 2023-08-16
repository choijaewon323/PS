#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;

	vector<pair<int, int>> meetings;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		meetings.push_back({ a, b });
	}

	sort(meetings.begin(), meetings.end(), compare);

	int index = 0;
	int answer = 0;
	int last = -1;

	while (index < meetings.size()) {
		int start = meetings[index].first;
		int end = meetings[index].second;

		if (last <= start) {
			answer++;
			last = end;
		}
		index++;
	}

	cout << answer << '\n';

	return 0;
}