#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> categories;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int n;
		cin >> n;

		categories.clear();

		if (n == 0) {
			cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i < n; i++) {
			string name, category;
			cin >> name >> category;

			categories[category]++;
		}

		int result = 1;
		for (auto iter = categories.begin(); iter != categories.end(); iter++) {
			result *= (iter->second) + 1;
		}
		cout << result - 1 << '\n';
	}

	return 0;
}