#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

int N;
vector<int> arr;

int absolute(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

bool inRange(int index) {
	if (0 <= index && index < N) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	arr = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = N - 1;
	int acc = 2E9;
	pair<int, int> result = { -1, -1 };
	while (start < end) {
		int present = arr[start] + arr[end];
		int absResult = absolute(present);

		if (absResult < acc) {
			acc = absResult;
			result = { arr[start], arr[end] };
		}

		if (present < 0) {
			start++;
		} else {
			end--;
		}
	}

	cout << result.first << " " << result.second << '\n';

	return 0;
}