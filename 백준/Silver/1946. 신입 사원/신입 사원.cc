#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	for (int test = 0; test < T; test++) {
		int N;
		cin >> N;
		vector<pair<int, int>> lists;

		for (int i = 0; i < N; i++) {
			int paper, speaking;
			cin >> paper >> speaking;
			lists.push_back({ paper, speaking });
		}

		if (lists.size() == 1) {
			cout << 1 << '\n';
			continue;
		}

		sort(lists.begin(), lists.end());

		int best = lists[0].second;
		int answer = 0;

		for (int i = 0; i < N; i++) {
			if (lists[i].second <= best) {
				answer++;
				best = lists[i].second;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}