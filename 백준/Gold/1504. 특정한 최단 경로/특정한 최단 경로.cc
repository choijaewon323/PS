#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1000000000
#define MAX 800

int N;
int E;
int dist[MAX + 1];
int v1, v2;

vector<pair<int, int>> edges[MAX + 1];

void input() {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	cin >> v1 >> v2;
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

			if (dist[next] >= nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}

	return -1;
}

int v1First() {
	int result = 0;

	const int startToV1 = dijkstra(1, v1);
	if (startToV1 == -1) {
		return -1;
	}
	result += startToV1;

	const int v1ToV2 = dijkstra(v1, v2);
	if (v1ToV2 == -1) {
		return -1;
	}
	result += v1ToV2;
	
	const int v2ToN = dijkstra(v2, N);
	if (v2ToN == -1) {
		return -1;
	}
	result += v2ToN;

	return result;
}

int v2First() {
	int result = 0;

	const int startToV2 = dijkstra(1, v2);
	if (startToV2 == -1) {
		return -1;
	}
	result += startToV2;

	const int v2ToV1 = dijkstra(v2, v1);
	if (v2ToV1 == -1) {
		return -1;
	}
	result += v2ToV1;

	const int v1ToN = dijkstra(v1, N);
	if (v1ToN == -1) {
		return -1;
	}
	result += v1ToN;

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	
	const int result1 = v1First();
	const int result2 = v2First();

	if (result1 == -1 && result2 == -1) {
		cout << -1 << '\n';
	}
	else if (result1 == -1) {
		cout << result2 << '\n';
	}
	else if (result2 == -1) {
		cout << result1 << '\n';
	}
	else {
		cout << min(result1, result2) << '\n';
	}
	
	return 0;
}