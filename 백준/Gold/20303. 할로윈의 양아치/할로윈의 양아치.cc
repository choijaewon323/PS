#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 30000

vector<pair<int, int>> friends;
int groupCount[MAX + 1];
int N, M, K;
int candy[MAX + 1];
int parent[MAX + 1];
int dp[MAX + 1][3000];

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] != x) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	if (a < b) {
		parent[b] = a;
		candy[a] += candy[b];
		candy[b] = 0;
	} else {
		parent[a] = b;
		candy[b] += candy[a];
		candy[a] = 0;
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> candy[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		friends.push_back({ a,b });
	}
}

void allFriendMerge() {
	init();
	for (pair<int, int> &f : friends) {
		merge(f.first, f.second);
	}
}

void calculateCount() {
	for (int i = 1; i <= N; i++) {
		int present = find(i);
		groupCount[present]++;
	}
}

vector<int> getGroupList() {
	vector<int> result;
	result.push_back(0);
	for (int i = 1; i <= N; i++) {
		if (groupCount[i] > 0) {
			result.push_back(i);
		}
	}
	return result;
}

int findMaxCandy() {
	int result = 0;
	vector<int> groupList = getGroupList();
	int size = groupList.size();
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < K; j++) {
			int present = groupList[i];
			if (j - groupCount[present] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - groupCount[present]] + candy[present]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			result = max(result, dp[i][j]);
		}
	}
	return result;
}

int solve() {
	allFriendMerge();
	calculateCount();
	int result = findMaxCandy();
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';
	return 0;
}