#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
	핵심 : 비싼 보석을 가장 작은 가방으로 해결하기

*/

int N, K;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

typedef long long ll;

ll solve(vector<pair<int, int>> &jewelry, multiset<int> &package) {
	int maxSize = package.size();
	ll result = 0;

	for (pair<int, int> &jewel : jewelry) {
		int weight = jewel.first;
		int price = jewel.second;

		auto iter = package.lower_bound(weight);

		if (iter != package.end()) {
			result += price;
			package.erase(iter);
		}
	}
	
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	vector<pair<int, int>> jewelry;
	for (int i = 0; i < N; i++) {
		int m, v;

		cin >> m >> v;

		jewelry.push_back({ m, v });
	}

	multiset<int> package;
	for (int i = 0; i < K; i++) {
		int c;
		cin >> c;
		package.insert(c);
	}

	sort(jewelry.begin(), jewelry.end(), compare);

	ll answer = solve(jewelry, package);

	cout << answer << '\n';

	return 0;
}