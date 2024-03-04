#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
using namespace std;

#define N_MAX 1000
#define INF 1000000000

struct Compare {
	bool operator() (pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

int N, M, X;
vector<pair<int, int>> edges[N_MAX + 1];

vector<int> dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	vector<int> dist(N + 1, INF);
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int present = pq.top().first;
		int presentCost = pq.top().second;
		pq.pop();

		for (pair<int, int>& edge : edges[present]) {
			int next = edge.first;
			int nextCost = edge.second + presentCost;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
	}

	int answer = -1;
	vector<int> returnCost = dijkstra(X);
	for (int i = 1; i <= N; i++) {
		vector<int> goCost = dijkstra(i);
		answer = max(answer, returnCost[i] + goCost[X]);
	}

	cout << answer << '\n';

	return 0;
}