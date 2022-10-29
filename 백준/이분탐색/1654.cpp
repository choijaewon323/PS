#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int64_t> lines;
	int64_t k, n, maxLine, temp, lowLine, mid, count, answer;
	cin >> k >> n;
	maxLine = 0;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		lines.push_back(temp);
		maxLine = max(maxLine, temp);
	}
	
	maxLine++;
	lowLine = 1;
	answer = 0;
	while (lowLine < maxLine) {
		mid = (lowLine + maxLine) / 2;
		count = 0;

		for (auto line : lines) {
			count += (line / mid);
		}

		if (count < n) {
			maxLine = mid;
		}
		else {
			if (answer < lowLine) {
				answer = mid;
			}
			lowLine = mid + 1;
		}
	}

	cout << answer << '\n';

	return 0;
}