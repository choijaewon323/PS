#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int64_t n, k;
	int64_t low, mid, high, answer, count;
	cin >> n;
	cin >> k;

	low = 1;
	answer = 0;
	high = n * n;

	while (low <= high) {
		mid = (low + high) / 2;
		count = 0;

		for (int i = 1; i <= n; i++) {
			count += min(n, mid / i);
		}

		if (count >= k) {
			answer = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	
	cout << answer << '\n';

	return 0;
}