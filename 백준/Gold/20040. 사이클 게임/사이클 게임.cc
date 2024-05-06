#include <iostream>
#include <vector>
using namespace std;

#define MAX 500000

vector<pair<int, int>> inputArray;
int parent[MAX];
int n, m;

void init() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (x != parent[x]) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		return false;
	}
	
	if (a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}

	return true;
}

void input() {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		inputArray.push_back({ x, y });
	}
}

int solve() {
	for (int answer = 0; answer < m; answer++) {
		pair<int, int> present = inputArray[answer];
		int a = present.first;
		int b = present.second;

		if (!merge(a, b)) {
			return answer + 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}