#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
using namespace std;

#define MAX 500000

typedef long long ll;

int N;
int A[MAX];
int B[1000000 + 1];
ll segment[MAX * 4];

ll query(int node, int start, int end, int left, int right) {
	if (left > right) {
		return 0;
	}

	if (end < left || right < start) {
		return 0;
	}

	if (left <= start && end <= right) {
		return segment[node];
	}

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) +
		query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index) {
	if (index < start || end < index) {
		return;
	}

	segment[node]++;
	
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index);
		update(node * 2 + 1, mid + 1, end, index);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		B[tmp] = i;
	}
	
	ll answer = 0;
	for (int i = 0; i < N; i++) {
		int upNum = A[i];

		int bottomIndex = B[upNum];

		answer += query(1, 0, N - 1, bottomIndex + 1, N - 1);
		update(1, 0, N - 1, bottomIndex);
	}

	cout << answer << '\n';

	return 0;
}