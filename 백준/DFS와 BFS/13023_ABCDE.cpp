#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
vector<list<int>> isFriend(2000);
bool discovered[2000];
int dfs(int start, int height, int n) {
	if (height == 5) {
		return 1;
	}
	discovered[start] = true;
	int result = 0;
	for (auto i : isFriend[start]) {
		if (start == i) {
			continue;
		}
		if (!discovered[i]) {
			discovered[i] = true;
			if (dfs(i, height + 1, n) == 1) {
				return 1;
			}
			discovered[i] = false;
		}
	}
	discovered[start] = false;
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		isFriend[a].push_back(b);
		isFriend[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (dfs(i, 1, n) == 1) {
			cout << 1 << '\n';
			return 0;
		}
		for (int i = 0; i < 2000; i++) {
			discovered[i] = false;
		}
	}
	cout << 0 << '\n';
	return 0;
}