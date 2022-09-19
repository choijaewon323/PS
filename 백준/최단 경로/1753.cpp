#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int v; // 정점의 개수
int k; // 시작 정점 번호
vector<pair<int, int>> adj[20001];
vector<int> dijkstra(int src) {
	vector<int> dist(v + 1, INT32_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main() {
	int e;

	cin >> v >> e;

	cin >> k;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	vector<int> result = dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (result[i] == INT32_MAX) {
			cout << "INF" << '\n';
		}
		else {
			cout << result[i] << '\n';
		}
	}

	return 0;
}