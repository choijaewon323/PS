#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000
#define INF 1000000000

int N, K, W;
int incoming[MAX + 1];
int cost[MAX + 1];
vector<int> edges[MAX + 1];
int result[MAX + 1];

void init() {
	for (int i = 0; i < MAX + 1; i++) {
		incoming[i] = 0;
		edges[i].clear();
		result[i] = 0;
	}
}

int solve() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (incoming[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int present = q.front();
		q.pop();

		if (present == W) {
			return result[W] + cost[W];
		}

		for (int next : edges[present]) {
			incoming[next]--;
			
			result[next] = max(result[next], result[present] + cost[present]);
			if (incoming[next] == 0) {
				q.push(next);
			}
		}
	}
	return -1;
}

void input() {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		init();
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			edges[x].push_back(y);
			incoming[y]++;
		}
		cin >> W;

		cout << solve() << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}