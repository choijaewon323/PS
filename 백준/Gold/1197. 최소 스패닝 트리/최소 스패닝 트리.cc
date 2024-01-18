#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000

struct node {
	int a;
	int b;
	int cost;
};

int parent[MAX + 1];

void init(int V) {
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] != x) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

bool merge(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot) {
		return false;
	}

	if (aRoot < bRoot) {
		parent[bRoot] = aRoot;
	}
	else {
		parent[aRoot] = bRoot;
	}
	return true;
}

bool compare(node &a, node &b) {
	return a.cost < b.cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, E;

	cin >> V >> E;

	vector<node> nodes;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		node temp = { a, b, c };
		nodes.push_back(temp);
	}

	sort(nodes.begin(), nodes.end(), compare);

	init(V);

	int answer = 0;
	for (node &nd : nodes) {
		if (merge(nd.a, nd.b)) {
			answer += nd.cost;
		}
	}

	cout << answer << '\n';

	return 0;
}