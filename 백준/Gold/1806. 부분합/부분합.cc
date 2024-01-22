#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

int N, S;
int arr[MAX];

int input() {
	cin >> N >> S;

	int acc = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		acc += arr[i];
	}

	return acc;
}

bool isBaseCase(const int acc) {
	if (acc < S) {
		cout << 0 << '\n';
		return true;
	}

	if (acc == S) {
		cout << N << '\n';
		return true;
	}

	return false;
}

int length(const int left, const int right) {
	return right - left + 1;
}

int solve() {
	int left = 0;
	int right = 0;
	int acc = arr[left];
	int result = N;

	while (left <= right && right < N) {
		if (left == right) {
			if (acc >= S) {
				return 1;
			}
			else {
				right++;
				if (right < N) {
					acc += arr[right];
				}
			}
		}
		else {
			if (acc >= S) {
				result = min(result, length(left, right));
				acc -= arr[left];
				left++;
			}
			else {
				right++;
				if (right < N) {
					acc += arr[right];
				}
			}
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int acc = input();

	if (isBaseCase(acc)) {
		return 0;
	}

	cout << solve() << '\n';

	return 0;
}