#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1000000001
#define MAX 1000

int N, M;
int dist[MAX + 1];
int A, B;

vector<pair<int, int>> edges[MAX + 1];

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		edges[a].push_back({ b, c });
	}

	cin >> A >> B;
}

void init() {
	for (int i = 1; i <= MAX; i++) {
		dist[i] = INF;
	}
}

struct compare {
	bool operator() (pair<int, int> &a, pair<int, int> &b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

int dijkstra(const int start, const int target) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	init();

	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int present = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (present == target) {
			return dist[present];
		}

		for (int i = 0; i < edges[present].size(); i++) {
			int next = edges[present][i].first;
			int nextCost = edges[present][i].second + cost;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << dijkstra(A, B) << '\n';
	
	return 0;
}