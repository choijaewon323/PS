#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 100000

int V;
vector<pair<int, int>> edges[MAX + 1];

int leaf;
int maxCost;
bool visited[MAX + 1];

void findLeaf(const int start, const int cost) {
	visited[start] = true;

	for (int i = 0; i < edges[start].size(); i++) {
		int next = edges[start][i].first;
		int nextCost = edges[start][i].second;

		if (!visited[next]) {
			findLeaf(next, cost + nextCost);
		}
	}

	if (maxCost < cost) {
		maxCost = cost;
		leaf = start;
	}
}

void init() {
	for (int i = 1; i <= V; i++) {
		visited[i] = false;
	}
}

void input() {
	cin >> V;

	for (int i = 0; i < V; i++) {
		int num;
		cin >> num;

		while (true) {
			int vertex;
			cin >> vertex;

			if (vertex == -1) {
				break;
			}

			int cost;
			cin >> cost;

			edges[num].push_back({ vertex, cost });
		}
	}
}

int solve(const int start) {
	visited[start] = true;

	int result = 0;
	for (int i = 0; i < edges[start].size(); i++) {
		int next = edges[start][i].first;
		int cost = edges[start][i].second;

		if (!visited[next]) {
			result = max(result, solve(next) + cost);
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	findLeaf(1, 0);

	init();

	cout << solve(leaf) << '\n';

	return 0;
}