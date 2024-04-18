#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 100000

vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
int N;
int parent[MAX];

struct Edge {
	int a;
	int b;
	int dist;
};

vector<Edge> edges;

bool compare(Edge &a, Edge &b) {
	return a.dist < b.dist;
}

bool compare2(pair<int, int> &a, pair<int, int> &b) {
	return a.second < b.second;
}

void init() {
	for (int i = 0; i < N; i++) {
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
	} else {
		parent[aRoot] = bRoot;
	}
	return true;
}

int absolute(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	init();
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		
		X.push_back({ i, x });
		Y.push_back({ i, y });
		Z.push_back({ i, z });
	}

	sort(X.begin(), X.end(), compare2);
	sort(Y.begin(), Y.end(), compare2);
	sort(Z.begin(), Z.end(), compare2);

	for (int i = 0; i < N - 1; i++) {
		edges.push_back({ X[i].first, X[i + 1].first, absolute(X[i].second - X[i + 1].second) });
		edges.push_back({ Y[i].first, Y[i + 1].first, absolute(Y[i].second - Y[i + 1].second) });
		edges.push_back({ Z[i].first, Z[i + 1].first, absolute(Z[i].second - Z[i + 1].second) });
	}

	sort(edges.begin(), edges.end(), compare);

	int answer = 0;
	for (Edge &edge : edges) {
		int a = edge.a;
		int b = edge.b;
		int dist = edge.dist;

		if (merge(a, b)) {
			answer += dist;
		}
	}

	cout << answer << '\n';

	return 0;
}