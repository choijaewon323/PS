#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	map<string, int> nameList;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		nameList[temp]++;
	}

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		nameList[temp]++;
	}

	vector<string> results;
	int result = 0;

	for (auto n : nameList) {
		if (n.second == 2) {
			result++;
			results.push_back(n.first);
		}
	}

	sort(results.begin(), results.end());

	cout << result << '\n';
	
	for (auto r : results) {
		cout << r << '\n';
	}

	return 0;
}