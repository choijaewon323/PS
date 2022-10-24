#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, less<int>> left;
	priority_queue<int, vector<int>, greater<int>> right;
	int mid;
	int n;
	int temp;
	cin >> n;

	if (n == 1) {
		cin >> temp;
		cout << temp << '\n';
		return 0;
	}

	if (n == 2) {
		int temp1;
		cin >> temp1;
		cout << temp1 << '\n';
		int temp2;
		cin >> temp2;
		cout << min(temp1, temp2) << '\n';
		return 0;
	}

	cin >> temp;	// n == 1
	mid = temp;
	cout << mid << '\n';
	cin >> temp;	// n == 2
	right.push(max(mid, temp));
	mid = min(mid, temp);
	cout << mid << '\n';
	for (int i = 3; i <= n; i++) {
		cin >> temp;
		if (mid <= temp) {
			right.push(temp);
		}
		else {
			left.push(temp);
		}

		int leftSize = left.size();
		int rightSize = right.size();
		int sub;
		if (i % 2 == 0) {	// Â¦¼ö
			if (leftSize > rightSize) {
				sub = leftSize - rightSize;
				for (int i = 0; i < sub; i++) {
					int num = left.top();
					left.pop();
					right.push(mid);
					mid = num;
				}
			}
			else if (leftSize + 1 < rightSize) {
				sub = rightSize - leftSize - 1;
				for (int i = 0; i < sub; i++) {
					int num = right.top();
					right.pop();
					left.push(mid);
					mid = num;
				}
			}
		}
		else {	// È¦¼ö
			// ºÒ±ÕÇüÀÌ¶ó¸é ¸ÂÃß±â
			if (leftSize > rightSize) {
				sub = leftSize - rightSize - 1;
				for (int i = 0; i < sub; i++) {
					int num = left.top();
					left.pop();
					right.push(mid);
					mid = num;
				}
			}
			else if (leftSize < rightSize) {
				sub = rightSize - leftSize - 1;
				for (int i = 0; i < sub; i++) {
					int num = right.top();
					right.pop();
					left.push(mid);
					mid = num;
				}
			}
		}
		cout << mid << '\n';
	}

	return 0;
}