#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 100000

int n;
vector<int> edges[MAX + 1];
vector<int> invert[MAX + 1];
stack<int> st;
vector<int> scc;
vector<bool> visited;
bool answer[MAX + 1];

void init() {
	st = stack<int>();
	visited = vector<bool>(n + 1, false);
	for (int i = 0; i < MAX + 1; i++) {
		edges[i].clear();
		invert[i].clear();
		answer[i] = false;
	}
}

void dfs(int here) {
	visited[here] = true;
	
	for (int next : edges[here]) {
		if (!visited[next]) {
			dfs(next);
		}
	}

	st.push(here);
}

void findScc(int here) {
	visited[here] = true;

	for (int next : invert[here]) {
		if (!visited[next]) {
			findScc(next);
		}
	}

	scc.push_back(here);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		
		cin >> n;
		init();
		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;

			edges[i].push_back(temp);
			invert[temp].push_back(i);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}

		visited = vector<bool>(n + 1, false);
		while (!st.empty()) {
			int here = st.top();
			st.pop();

			if (!visited[here]) {
				scc.clear();
				findScc(here);
				
				if (scc.size() == 1) {
					if (edges[here].back() == here) {
						answer[here] = true;
					}
				} else {
					for (int s : scc) {
						answer[s] = true;
					}
				}
			}
		}

		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (!answer[i]) {
				result++;
			}
		}

		cout << result << '\n';
	}

	return 0;
}