#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 100000
#define INF 1000000001

struct Node {
	int num;
	int index;
};

int N, M;
int arr[MAX + 1];
Node segment[MAX * 4 + 1];


Node init(int start, int end, int node) {
	if (start == end) {
		return segment[node] = { arr[start], start };
	}

	int mid = (start + end) / 2;
	
	Node n1 = init(start, mid, node * 2);
	Node n2 = init(mid + 1, end, node * 2 + 1);

	if (n1.num < n2.num) {
		segment[node] = n1;
	} else if (n1.num > n2.num) {
		segment[node] = n2;
	} else {
		if (n1.index < n2.index) {
			segment[node] = n1;
		} else {
			segment[node] = n2;
		}
	}
	return segment[node];
}

Node findMin(int start, int end, int node, int left, int right) {
	if (end < left || right < start) {
		return { INF, -1 };
	}

	if (left <= start && end <= right) {
		return segment[node];
	}

	int mid = (start + end) / 2;

	Node n1 = findMin(start, mid, node * 2, left, right);
	Node n2 = findMin(mid + 1, end, node * 2 + 1, left, right);

	if (n1.num < n2.num) {
		return n1;
	} else if (n1.num > n2.num) {
		return n2;
	} else {
		if (n1.index < n2.index) {
			return n1;
		} else {
			return n2;
		}
	}
}

Node update(int start, int end, int node, int index, int num) {
	if (index < start || index > end) {
		return segment[node];
	}

	if (start == end) {
		return segment[node] = { num, index };
	}

	int mid = (start + end) / 2;

	Node n1 = update(start, mid, node * 2, index, num);
	Node n2 = update(mid + 1, end, node * 2 + 1, index, num);

	if (n1.num < n2.num) {
		segment[node] = n1;
	} else if (n1.num > n2.num) {
		segment[node] = n2;
	} else {
		if (n1.index < n2.index) {
			segment[node] = n1;
		} else {
			segment[node] = n2;
		}
	}
	return segment[node];
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, N, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		if (a == 1) {
			update(1, N, 1, b, c);
		} else if (a == 2) {
			Node result = findMin(1, N, 1, b, c);

			cout << result.index << '\n';
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