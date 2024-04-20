#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 1000000

typedef long long LL;

LL segment[MAX * 8 + 1];
LL arr[MAX + 1];
LL N, M, K;

LL init(int start, int end, int node) {
	if (start == end) {
		return segment[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return segment[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

LL sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}

	if (left <= start && end <= right) {
		return segment[node];
	}
	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) +
		sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, LL dif) {
	if (index < start || index > end) {
		return;
	}

	segment[node] += dif;
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		LL a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			LL dif = c - arr[b];
			arr[b] = c;
			update(1, N, 1, b, dif);
		} else if (a == 2) {
			cout << sum(1, N, 1, b, c) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}