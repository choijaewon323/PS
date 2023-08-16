#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 100000000

vector<pair<int, int>> edges[50001];
int dist[50001];

int dijkstra(int start, int end) {
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;

	pq.push({ 0, 1 });

	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		int present = temp.second;
		int cost = -temp.first;
		pq.pop();

		if (cost > dist[present]) {
			continue;
		}

		for (int i = 0; i < edges[present].size(); i++) {
			int next = edges[present][i].first;
			int nextCost = edges[present][i].second + dist[present];

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}

	return dist[end];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	cout << dijkstra(1, N) << '\n';

	return 0;
}