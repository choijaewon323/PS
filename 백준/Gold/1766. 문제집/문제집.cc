#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 32000

vector<int> edges[MAX + 1];
int N, M;
int incoming[MAX + 1];

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		incoming[b]++;
	}
}

void solve() {
	priority_queue<int, vector<int>, greater<int>> minPQ;
	
	for (int i = 1; i <= N; i++) {
		if (!incoming[i]) {
			minPQ.push(i);
		}
	}

	while (!minPQ.empty()) {
		int present = minPQ.top();
		minPQ.pop();

		cout << present << " ";

		for (int next : edges[present]) {
			incoming[next]--;

			if (!incoming[next]) {
				minPQ.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}