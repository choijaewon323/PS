#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int64_t> arr;

int binary_search(int64_t start, int64_t end, int64_t num) {
	int64_t mid = (start + end) / 2;

	if (start == end) {	// base case
		if (arr[start] == num) {
			return 1;
		}
		else {
			return 0;
		}
	}

	if (arr[mid] == num) {
		return 1;
	}
	else if (arr[mid] > num) {
		return binary_search(start, mid, num);
	}
	else {
		return binary_search(mid + 1, end, num);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int64_t n, m, temp, size;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	
	cin >> m;
	size = arr.size();
	for (int i = 0; i < m; i++) {
		cin >> temp;
		cout << binary_search(0, size - 1, temp) << '\n';
	}

	return 0;
}