#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 4000000

int N, M, K;
vector<int> numbers;

int parent[MAX];

void init() {
	for (int i = 0; i < M; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] != x) {
		return parent[x] = find(parent[x]);
	}
	return x;
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		return;
	}

	if (a < b) {
		parent[a] = b;
	} else {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	init();
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < K; i++) {
		int oppo;
		cin >> oppo;

		int index = upper_bound(numbers.begin(), numbers.end(), oppo) - numbers.begin();
		index = find(index);

		int my = numbers[index];
		merge(index, index + 1);

		cout << my << '\n';
	}

	return 0;
}