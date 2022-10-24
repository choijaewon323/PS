#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
	int64_t n, result = 0;
	
	cin >> n;
	if (n == 1) {
		int temp;
		cin >> temp;
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int temp;
	
		cin >> temp;
		pq.push(temp);
	}

	while (pq.size() >= 2) {
		int64_t temp1 = pq.top();
		pq.pop();
		int64_t temp2 = pq.top();
		pq.pop();
		result += (temp1 + temp2);
		pq.push(temp1 + temp2);
	}

	cout << result << '\n';
	
	return 0;
}