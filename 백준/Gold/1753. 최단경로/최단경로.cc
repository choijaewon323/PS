#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1000000000
#define MAX 20000

int V;
int E;
int K;
int dist[MAX + 1];

vector<pair<int, int>> edges[MAX + 1];

void input() {
	cin >> V >> E;

	cin >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;

		edges[u].push_back({ v, w });
	}
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

void dijkstra(const int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int present = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < edges[present].size(); i++) {
			int next = edges[present][i].first;
			int nextCost = edges[present][i].second + cost;

			if (dist[next] >= nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	init();
	dijkstra(K);
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}

		cout << dist[i] << '\n';
	}
	
	return 0;
}