#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int city[51][51];
int absolute(int num) {
	return num > 0 ? num : -num;
}
int func(int n, int m, vector<pair<int, int>>& chicken, vector<pair<int, int>>& house,
	vector<int>& indexOfChicken) {
	if (m == indexOfChicken.size()) {
		int result = 0;
		for (auto tempHouse : house) {
			int temp = INT16_MAX;
			for (auto index : indexOfChicken) {
				int length = absolute(tempHouse.first - chicken[index].first) 
					+ absolute(tempHouse.second - chicken[index].second);
				temp = min(temp, length);
			}
			result += temp;
		}
		return result;
	}
	if (indexOfChicken.empty()) {
		int result = INT16_MAX;
		for (int i = 0; i < chicken.size() - m + 1; i++) {
			indexOfChicken.push_back(i);
			result = min(result, func(n, m, chicken, house, indexOfChicken));
			indexOfChicken.pop_back();
		}
		return result;
	}
	else {
		int result = INT16_MAX;
		for (int i = indexOfChicken.back() + 1; i < chicken.size(); i++) {
			indexOfChicken.push_back(i);
			result = min(result, func(n, m, chicken, house, indexOfChicken));
			indexOfChicken.pop_back();
		}
		return result;
	}
}
int main() {
	int n, m;
	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;
	vector<int> indexOfChicken;
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> city[y][x];
			if (city[y][x] == 1) {
				house.push_back(make_pair(y, x));
			}
			else if (city[y][x] == 2) {
				chicken.push_back(make_pair(y, x));
			}
		}
	}
	cout << func(n, m, chicken, house, indexOfChicken) << '\n';
	return 0;
}