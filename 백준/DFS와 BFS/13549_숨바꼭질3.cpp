#include <iostream>
#include <queue>
using namespace std;
int sec[300001];
int bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	sec[n] = 0;
	while (!q.empty()) {
		int present = q.front();
		q.pop();
		if (present == k) {
			continue;
		}
		if (present - 1 >= 0) {
			if (sec[present - 1] == -1 || sec[present - 1] > sec[present] + 1) {
				sec[present - 1] = sec[present] + 1;
				q.push(present - 1);
			}
		}
		if (present + 1 <= 300000) {
			if (sec[present + 1] == -1 || sec[present + 1] > sec[present] + 1) {
				sec[present + 1] = sec[present] + 1;
				q.push(present + 1);
			}
		}
		if (present != 0 && present * 2 <= 300000) {
			if (sec[present * 2] == -1 || sec[present * 2] > sec[present]) {
				sec[present * 2] = sec[present];
				q.push(present * 2);
			}
		}
	}
	return sec[k];
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 100001; i++) {
		sec[i] = -1;
	}
	cout << bfs(n, k) << '\n';
	return 0;
}