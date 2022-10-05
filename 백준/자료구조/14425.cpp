#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n, m;
	int result = 0;
	map<string, int> mp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		mp[temp]++;
	}

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;

		if (mp[temp] > 0) {
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}