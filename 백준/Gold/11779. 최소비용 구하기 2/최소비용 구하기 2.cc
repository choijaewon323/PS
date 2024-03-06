#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

#define MAX 1000
#define INF 1000000000000000ll
typedef long long LL;

int n, m;
vector<pair<int, int>> edges[MAX + 1];

struct Node {
	int index;
	LL cost;
	vector<int> path;
};

struct Compare {
	bool operator() (Node &a, Node &b) {
		return a.cost > b.cost;
	}
};

Node dijkstra(int start, int end) {
	priority_queue<Node, vector<Node>, Compare> pq;
	vector<LL> dist(MAX + 1, INF);
	
	dist[start] = 0;
	vector<int> startPath = { start };
	pq.push({ start, 0, startPath });

	while (!pq.empty()) {
		Node present = pq.top();
		pq.pop();

		if (present.index == end) {
			return present;
		}

		for (int i = 0; i < edges[present.index].size(); i++) {
			int next = edges[present.index][i].first;
			LL nextCost = edges[present.index][i].second + present.cost;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				vector<int> nextPath = present.path;
				nextPath.push_back(next);
				pq.push({ next, nextCost, nextPath });
			}
		}
	}

	return { -1, -1, vector<int>() };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
	}
	int start, end;
	cin >> start >> end;

	Node result = dijkstra(start, end);

	cout << result.cost << '\n';
	cout << result.path.size() << '\n';
	for (int p : result.path) {
		cout << p << " ";
	}
	cout << '\n';

	return 0;
}