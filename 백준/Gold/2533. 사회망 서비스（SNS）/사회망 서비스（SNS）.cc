#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000000

vector<int> edges[MAX + 1];
int dp[MAX + 1][2];
int N;
bool visited[MAX + 1];

void solve(int here) {
	visited[here] = true;

	dp[here][1] = 1;
	for (int next : edges[here]) {
		if (visited[next]) {
			continue;
		}

		solve(next);
		dp[here][0] += dp[next][1];
		dp[here][1] += min(dp[next][0], dp[next][1]);
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve(1);
	cout << min(dp[1][0], dp[1][1]) << '\n';

	return 0;
}