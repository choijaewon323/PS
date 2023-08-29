#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;

bool binarySearch(int num) {
	int left = 0;
	int right = B.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (B[mid] == num) {
			return true;
		}
		if (B[mid] > num) {
			right = mid - 1;
			continue;
		}
		if (B[mid] < num) {
			left = mid + 1;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;

	cin >> a >> b;
	
	for (int i = 0; i < a; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	for (int i = 0; i < b; i++) {
		int temp;
		cin >> temp;
		B.push_back(temp);
	}

	sort(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		if (binarySearch(A[i])) {
			a--;
			b--;
		}
	}

	cout << a + b << '\n';

	return 0;
}