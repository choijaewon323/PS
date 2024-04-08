#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100
#define INF 1000000000

struct Edge {
	int num;
	int weight;
};
struct Compare {
	bool operator() (Edge &a, Edge &b) {
		return a.weight > b.weight;
	}
};

int section[MAX + 1];
int n, m, r;
vector<Edge> edges[MAX + 1];

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> section[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		edges[a].push_back({ b, l });
		edges[b].push_back({ a, l });
	}
}

int dijkstra(int start) {
	priority_queue<Edge, vector<Edge>, Compare> pq;
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int present = pq.top().num;
		int cost = pq.top().weight;
		pq.pop();

		for (Edge &edge : edges[present]) {
			int next = edge.num;
			int nextCost = cost + edge.weight;

			if (dist[next] > nextCost && nextCost <= m) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			result += section[i];
		}
	}

	return result;
}

int solve() {
	int result = -1;
	for (int i = 1; i <= n; i++) {
		result = max(result, dijkstra(i));
	}
	return result;
}

int main() {
	input();
	cout << solve() << '\n';
	return 0;
}