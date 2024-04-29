#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MAX 1000

int N, M;
vector<int> edges[MAX + 1];
int incoming[MAX + 1];
int visited[MAX + 1];

bool dfs(int now) {
	if (visited[now] == -1) {
		return true;
	}
	if (visited[now] == 1) {
		return false;
	}
	visited[now] = -1;
	for (int next : edges[now]) {
		if (dfs(next)) {
			return true;
		}
	}
	visited[now] = 1;
	return false;
}

bool isCycle() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bool result = dfs(i);

			if (result) {
				return true;
			}
		}
	}
	return false;
}

void topoSort() {
	queue<int> q;
	
	for (int i = 1; i <= N; i++) {
		if (!incoming[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int present = q.front();
		q.pop();

		cout << present << '\n';

		for (int next : edges[present]) {
			incoming[next]--;

			if (!incoming[next]) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int cnt;
		cin >> cnt;

		vector<int> temp(cnt);
		for (int i = 0; i < cnt; i++) {
			cin >> temp[i];
		}

		for (int i = 1; i < cnt; i++) {
			int prev = temp[i - 1];
			int here = temp[i];

			edges[prev].push_back(here);
			incoming[here]++;
		}
	}

	if (isCycle()) {
		cout << 0 << '\n';
	} else {
		topoSort();
	}

	return 0;
}