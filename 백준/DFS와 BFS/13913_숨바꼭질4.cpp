#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
int dist[100001];
int bfs(int start, int k, vector<int>& parent) {
	queue<int> q;
	dist[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int present = q.front();
		q.pop();
		if (present == k) {
			return dist[present] - 1;
		}
		int next = present - 1;
		if (next >= 0) {
			if (dist[next] == 0) {
				dist[next] = dist[present] + 1;
				q.push(next);
				parent[next] = present;
			}
		}
		next = present + 1;
		if (next <= 100000) {
			if (dist[next] == 0) {
				dist[next] = dist[present] + 1;
				q.push(next);
				parent[next] = present;
			}
		}
		next = present * 2;
		if (next != 0 && next <= 100000) {
			if (dist[next] == 0) {
				dist[next] = dist[present] + 1;
				q.push(next);
				parent[next] = present;
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n, k;
	vector<int> parent(100001);
	cin >> n >> k;
	int result = bfs(n, k, parent);
	cout << result << '\n';
	if (result == 0) {
		cout << n << '\n';
		return 0;
	}
	vector<int> answer;
	int temp = k;
	answer.push_back(k);
	while (true) {
		if (parent[temp] == n) {
			answer.push_back(n);
			break;
		}
		answer.push_back(parent[temp]);
		temp = parent[temp];
	}
	reverse(answer.begin(), answer.end());
	for (auto i : answer) {
		cout << i << " ";
	}
	cout << '\n';
	return 0;
}