#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 10000

int V, E;
vector<int> edges[MAX + 1];
vector<int> transpose[MAX + 1];
stack<int> st;
vector<bool> visited;
vector<int> temp;

void input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		transpose[b].push_back(a);
	}
}

void dfs(int start) {
	visited[start] = true;

	for (int next : edges[start]) {
		if (!visited[next]) {
			dfs(next);
		}
	}

	st.push(start);
}

void findScc(int start) {
	visited[start] = true;

	temp.push_back(start);
	for (int next : transpose[start]) {
		if (!visited[next]) {
			findScc(next);
		}
	}
}

vector<vector<int>> solve() {
	vector<vector<int>> result;

	visited = vector<bool>(V + 1, false);
	for (int i = 1; i <= V; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	visited = vector<bool>(V + 1, false);
	while (!st.empty()) {
		int here = st.top();
		st.pop();

		if (!visited[here]) {
			temp.clear();
			findScc(here);
			sort(temp.begin(), temp.end());
			result.push_back(temp);
		}
	}
	sort(result.begin(), result.end());

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	vector<vector<int>> answer = solve();
	cout << answer.size() << '\n';
	for (vector<int> &scc : answer) {
		int size = scc.size();

		for (int i = 0; i < size; i++) {
			int num = scc[i];

			cout << num << " ";

			if (i == size - 1) {
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}