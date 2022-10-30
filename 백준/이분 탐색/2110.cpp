#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coord;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c, temp;
	int start, end, mid, prev, size, answer;
	int count;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		coord.push_back(temp);
	}
	sort(coord.begin(), coord.end());

	start = 1;
	end = coord.back() - coord.front() + 1;
	size = coord.size();
	answer = -1;
	while (start + 1 < end) {
		mid = (start + end) / 2;

		prev = coord.front();
		count = 1;
		for (int i = 1; i < size; i++) {
			if (coord[i] - prev >= mid) {
				count++;
				prev = coord[i];
			}
		}

		if (count >= c) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	
	cout << start << '\n';

	return 0;
}