#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int b, c;
	cin >> b >> c;
	int64_t answer = 0;
	for (auto i : v) {
		int result1 = 0;
		int result2 = 0;
		// case 1
		int temp = i - b;
		result1++;
		if (temp > 0) {
			result1 += temp / c;
			if (temp % c != 0) {
				result1++;
			}
		}
		// case 2
		//result2 += i / c;
		//if (i % c != 0) {
		//	result2++;
		//}
		answer += result1;
	}
	cout << answer << '\n';
	return 0;
}