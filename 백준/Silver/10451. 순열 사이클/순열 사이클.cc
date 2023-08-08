#include <iostream>
#include <vector>

using namespace std;

vector<int> edges;
vector<bool> visited;

void dfs(int start) {
	visited[start] = true;

	int next = edges[start];

	if (!visited[next]) {
		dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;
	for (int test = 0; test < T; test++) {
		int N;

		cin >> N;

		edges = vector<int>(N + 1);
		visited = vector<bool>(N + 1, false);

		for (int i = 1; i <= N; i++) {
			int temp;
			cin >> temp;
			edges[i] = temp;
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				cnt++;
				dfs(i);
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}