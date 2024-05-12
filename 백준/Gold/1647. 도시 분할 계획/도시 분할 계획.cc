#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000

struct Edge {
	int a;
	int b;
	int cost;
};

vector<Edge> edges;
int N, M;
int parent[MAX + 1];

bool compare(Edge &A, Edge &B) {
	return A.cost < B.cost;
}

void init() {
	for (int i = 1; i <= N; i++) {
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
	a = find(a);
	b = find(b);

	if (a == b) {
		return false;
	}

	if (a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
	return true;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edges.push_back({ A,B,C });
	}
}

int solve() {
	int result = 0;
	int last = -1;

	init();
	sort(edges.begin(), edges.end(), compare);
	for (Edge &edge : edges) {
		int a = edge.a;
		int b = edge.b;
		int cost = edge.cost;

		if (merge(a, b)) {
			result += cost;
			last = cost;
		}
	}

	return result - last;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}