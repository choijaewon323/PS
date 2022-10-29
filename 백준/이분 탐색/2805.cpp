#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int64_t> trees;
	int64_t n, m, temp;
	int64_t low, high;
	int64_t mid;
	int64_t cut;
	int64_t answer;
	cin >> n >> m;
	high = -1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		trees.push_back(temp);
		high = max(temp, high);
	}

	answer = -1;
	low = 0;
	while (low < high) {
		mid = (low + high) / 2;
		cut = 0;

		for (auto tree : trees) {
			if (tree > mid) {
				cut += (tree - mid);
			}
		}

		if (cut < m) {
			high = mid;
		}
		else {
			low = mid + 1;
			answer = max(answer, mid);
		}
	}

	cout << answer << '\n';

	return 0;
}