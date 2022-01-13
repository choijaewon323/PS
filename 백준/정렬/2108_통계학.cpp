#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
int freq[8001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	vector<int> numbers;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		sum += temp;
		numbers.push_back(temp);
	}
	cout << round(sum / n) << '\n';
	sort(numbers.begin(), numbers.end());
	cout << numbers[n / 2] << '\n';
	for (auto i : numbers) {
		freq[i + 4000]++;
	}
	int num = 0;
	for (int i = 0; i < 8001; i++) {
		if (freq[i] > num) {
			num = freq[i];
		}
	}
	vector<int> freqNum;
	for (int i = 0; i < 8001; i++) {
		if (freq[i] == num) {
			freqNum.push_back(i - 4000);
		}
	}
	sort(freqNum.begin(), freqNum.end());
	if (freqNum.size() == 1) {
		cout << freqNum.front() << '\n';
	}
	else {
		cout << freqNum[1] << '\n';
	}
	cout << numbers.back() - numbers.front() << '\n';
	return 0;
}