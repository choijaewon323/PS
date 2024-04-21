#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 100000
#define INF 1000000001

int maxSegment[MAX * 4 + 1];
int minSegment[MAX * 4 + 1];
int arr[MAX + 1];
int N, M;

int minInit(int start, int end, int node) {
	if (start == end) {
		return minSegment[node] = arr[start];
	}

	int mid = (start + end) / 2;
	
	return minSegment[node] = min(
		minInit(start, mid, node * 2),
		minInit(mid + 1, end, node * 2 + 1)
	);
}

int maxInit(int start, int end, int node) {
	if (start == end) {
		return maxSegment[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return maxSegment[node] = max(
		maxInit(start, mid, node * 2),
		maxInit(mid + 1, end, node * 2 + 1)
	);
}

int findMin(int start, int end, int node, int left, int right) {
	if (end < left || right < start) {
		return INF;
	}

	if (left <= start && end <= right) {
		return minSegment[node];
	}

	int mid = (start + end) / 2;
	return min(
		findMin(start, mid, node * 2, left, right),
		findMin(mid + 1, end, node * 2 + 1 , left, right)
	);
}

int findMax(int start, int end, int node, int left, int right) {
	if (end < left || right < start) {
		return -INF;
	}

	if (left <= start && end <= right) {
		return maxSegment[node];
	}

	int mid = (start + end) / 2;
	return max(
		findMax(start, mid, node * 2, left, right),
		findMax(mid + 1, end, node * 2 + 1, left, right)
	);
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	minInit(1, N, 1);
	maxInit(1, N, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		if (a > b) {
			swap(a, b);
		}

		cout << findMin(1, N, 1, a, b) << " " << findMax(1, N, 1, a, b) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}