#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 1000000
#define MOD 1000000007

typedef long long LL;

int N, M, K;
int arr[MAX + 1];
LL segment[MAX * 4 + 1];

LL init(int start, int end, int node) {
	if (start == end) {
		return segment[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return segment[node] = init(start, mid, node * 2) 
		* init(mid + 1, end, node * 2 + 1)
		% MOD;
}

LL mul(int start, int end, int node, int left, int right) {
	if (end < left || right < start) {
		return 1;
	}

	if (left <= start && end <= right) {
		return segment[node];
	}

	int mid = (start + end) / 2;

	LL result = mul(start, mid, node * 2, left, right)
		* mul(mid + 1, end, node * 2 + 1, left, right)
		% MOD;

	return result;
}

LL update(int start, int end, int node, int index, LL dif) {
	if (index < start || end < index) {
		return segment[node];
	}

	if (start == end) {
		return segment[node] = dif;
	}

	int mid = (start + end) / 2;

	return segment[node] = update(start, mid, node * 2, index, dif)
	* update(mid + 1, end, node * 2 + 1, index, dif)
		% MOD;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1) {
			update(1, N, 1, b, c);
			arr[b] = c;
		} else if (a == 2) {
			cout << mul(1, N, 1, b, c) << '\n';
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