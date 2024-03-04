#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define NODE_MAX 100000

int N;
vector<int> edges[NODE_MAX + 1];
int parent[NODE_MAX + 1];
bool visited[NODE_MAX + 1];

void dfs(int start, int prev) {
	visited[start] = true;
	parent[start] = prev;
	
	for (int next : edges[start]) {
		if (!visited[next]) {
			dfs(next, start);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1, -1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
	
	return 0;
}