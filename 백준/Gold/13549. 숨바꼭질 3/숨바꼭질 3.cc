#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
using namespace std;

#define MAX 300000
#define INF 1000000000

int N, K;

struct Compare {
	bool operator() (pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

bool inRange(int x) {
	if (0 <= x && x <= MAX) {
		return true;
	}
	return false;
}

int bfs(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
	vector<int> dist(MAX + 1, INF);
	q.push({ start , 0});
	dist[start] = 0;

	while (!q.empty()) {
		int present = q.top().first;
		int presentCost = q.top().second;
		q.pop();

		if (present == end) {
			return presentCost;
		}

		// * 2
		if (inRange(present * 2) && present != 0) {
			int next = present * 2;
			int nextCost = presentCost;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				q.push({ next, nextCost });
			}
		}

		// -1
		if (inRange(present - 1)) {
			int next = present - 1;
			int nextCost = presentCost + 1;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				q.push({ next, nextCost });
			}
		}

		// + 1
		if (inRange(present + 1)) {
			int next = present + 1;
			int nextCost = presentCost + 1;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				q.push({ next, nextCost });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	int answer = bfs(N, K);
	cout << answer << '\n';

	return 0;
}