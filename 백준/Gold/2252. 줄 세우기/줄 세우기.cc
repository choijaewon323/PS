#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 32000

int N, M;
vector<int> edges[MAX + 1];
vector<int> answer;
bool visited[MAX + 1];

void dfs(int start) {
	visited[start] = true;

	for (int next : edges[start]) {
		if (!visited[next]) {
			dfs(next);
		}
	}

	answer.push_back(start);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	reverse(answer.begin(), answer.end());

	for (int a : answer) {
		cout << a << " ";
	}
	cout << '\n';

	return 0;
}