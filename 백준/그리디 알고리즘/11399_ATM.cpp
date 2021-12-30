#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, answer = 0, sum = 0;
	vector<int> times;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		times.push_back(temp);
	}
	sort(times.begin(), times.end());
	for (auto time : times) {
		sum += time;
		answer += sum;
	}
	cout << answer << '\n';
	return 0;
}