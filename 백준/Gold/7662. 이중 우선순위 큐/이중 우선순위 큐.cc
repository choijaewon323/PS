#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int k;
		cin >> k;

		multiset<int> numbers;

		for (int command = 0; command < k; command++) {
			char c;
			int n;
			cin >> c >> n;

			if (c == 'D') {
				// delete
				if (numbers.empty()) {
					continue;
				}

				if (n == 1) {
					// max delete
					numbers.erase(--numbers.end());
				} else {
					// min delete
					numbers.erase(numbers.begin());
				}
			} else {
				// insert
				numbers.insert(n);
			}
		}

		if (numbers.empty()) {
			cout << "EMPTY" << '\n';
		} else {
			auto start = numbers.begin();
			auto end = --numbers.end();
			cout << *end << " " << *start << '\n';
		}
	}

	return 0;
}