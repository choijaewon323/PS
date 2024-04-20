#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector<pair<double, double>> stars;
struct Edge {
	int a;
	int b;
	double dist;
};
vector<Edge> edges;
int parent[100];

bool compare(Edge &a, Edge &b) {
	return a.dist < b.dist;
}

void init() {
	for (int i = 0; i < 100; i++) {
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;

		stars.push_back({ x, y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pair<double, double> &s1 = stars[i];
			pair<double, double> &s2 = stars[j];

			double x = s1.first - s2.first;
			double y = s1.second - s2.second;

			double dist = sqrt(x * x + y * y);
			
			edges.push_back({ i, j, dist });
		}
	}

	sort(edges.begin(), edges.end(), compare);
}

double solve() {
	double result = 0;

	for (Edge &edge : edges) {
		int a = edge.a;
		int b = edge.b;
		double dist = edge.dist;

		if (merge(a, b)) {
			result += dist;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	input();
	cout << fixed;
	cout.precision(2);
	cout << solve() << '\n';

	return 0;
}