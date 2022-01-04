#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ability[21][21];
int sum(vector<int>& team) {
	int result = 0;
	for (int i = 0; i < team.size(); i++) {
		for (int j = 0; j < team.size(); j++) {
			result += ability[team[i]][team[j]];
		}
	}
	return result;
}
int func(int n, vector<int>& startTeam) {
	if (startTeam.size() == n / 2) {
		vector<int> linkTeam;
		bool flag[21];
		for (int i = 0; i < 21; i++) {
			flag[i] = false;
		}
		for (int i = 0; i < startTeam.size(); i++) {
			flag[startTeam[i]] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (flag[i]) {
				continue;
			}
			linkTeam.push_back(i);
		}
		int start = sum(startTeam);
		int link = sum(linkTeam);
		int result = start - link;
		return result > 0 ? result : -result;
	}
	if (startTeam.empty()) {
		int result = INT16_MAX;
		for (int i = 1; i <= n; i++) {
			startTeam.push_back(i);
			result = min(result, func(n, startTeam));
			startTeam.pop_back();
		}
		return result;
	}
	else {
		int result = INT16_MAX;
		for (int i = startTeam.back() + 1; i <= n; i++) {
			startTeam.push_back(i);
			result = min(result, func(n, startTeam));
			startTeam.pop_back();
		}
		return result;
	}
}
int main() {
	int n;
	vector<int> startTeam;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ability[i][j];
		}
	}
	cout << func(n, startTeam) << '\n';
	return 0;
}