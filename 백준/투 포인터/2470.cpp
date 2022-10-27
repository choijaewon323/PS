#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> arr;
	int n, temp, result, resultStart, resultEnd;
	int tempSum;
	int start, end;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	
	start = 0;
	resultStart = 0;
	end = n - 1;
	resultEnd = n - 1;
	result = 2000000001;

	while (start < end) {
		tempSum = abs(arr[start] + arr[end]);
		if (tempSum < result) {
			resultStart = start;
			resultEnd = end;
			result = tempSum;
		}

		if (arr[start] + arr[end] < 0) {	// 음수
			start++;
		}
		else {	// 양수 혹은 0
			end--;
		}
	}

	cout << arr[resultStart] << " " << arr[resultEnd] << '\n';

	return 0;
}