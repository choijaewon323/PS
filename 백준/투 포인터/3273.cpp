#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr;
	int n, x, temp;
	int start, end;
	int tempSum, result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> x;

	sort(arr.begin(), arr.end());

	result = 0;
	tempSum = 0;
	start = 0;
	end = n - 1;
	while (start < end) {
		tempSum = arr[start] + arr[end];
		if (tempSum < x) {
			start++;
		}
		else if (tempSum > x) {
			end--;
		}
		else if (tempSum == x) {
			result++;
			end--;
		}
	}
	cout << result << '\n';

	return 0;
}