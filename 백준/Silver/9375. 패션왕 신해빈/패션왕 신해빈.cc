#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;

		cin >> n;

		if (n == 0) {
			cout << 0 << '\n';
			continue;
		}

		map<string, int> mp;

		for (int i = 0; i < n; i++) {
			string cloth;
			string category;

			cin >> cloth >> category;

			mp[category]++;
		}

		map<string, int>::iterator iter;

		int result = 1;
		for (iter = mp.begin(); iter != mp.end(); iter++) {
			result *= (iter->second) + 1;
		}

		cout << result - 1 << '\n';
	}

	return 0;
}