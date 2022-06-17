#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<list<int>> edges(200001, list<int>());
int visited[200001];
int seq;

void dfs(int start) {
	seq++;
	visited[start] = seq;

	for (auto i : edges[start]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 1; i <= 200000; i++) {
		edges[i].sort();
	}

	dfs(r);

	for (int i = 1; i <= n; i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}