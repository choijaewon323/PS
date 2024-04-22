#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 100000
#define INF 1000000001

typedef long long LL;

int arr[MAX + 1];
int segment[MAX * 4 + 1];
int N;

int init(int start, int end, int node) {
	if (start == end) {
		return segment[node] = start;
	}

	int mid = (start + end) / 2;

	int index1 = init(start, mid, node * 2);
	int index2 = init(mid + 1, end, node * 2 + 1);

	if (arr[index1] > arr[index2]) {
		segment[node] = index2;
	} else {
		segment[node] = index1;
	}

	return segment[node];
}

int findMin(int start, int end, int node, int left, int right) {
	if (end < left || right < start) {
		return -1;
	}

	if (left <= start && end <= right) {
		return segment[node];
	}

	int mid = (start + end) / 2;

	int index1 = findMin(start, mid, node * 2, left, right);
	int index2 = findMin(mid + 1, end, node * 2 + 1, left, right);

	if (index1 == -1 && index2 == -1) {
		return -1;
	} else if (index1 != -1 && index2 == -1) {
		return index1;
	} else if (index1 == -1 && index2 != -1) {
		return index2;
	} else {
		if (arr[index1] > arr[index2]) {
			return index2;
		} else {
			return index1;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

int func(int start, int end) {
	if (start > end) {
		return -1;
	}

	int width = end - start + 1;

	int minIndex = findMin(1, N, 1, start, end);
	int height = arr[minIndex];
	int present = height * width;

	int maxVal = max(present,
		max(func(start, minIndex - 1), func(minIndex + 1, end))
	);

	return maxVal;
}

int solve() {
	init(1, N, 1);
	return func(1, N);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	cout << solve() << '\n';

	return 0;
}