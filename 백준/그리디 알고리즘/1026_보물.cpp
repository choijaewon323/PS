#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector<int> a;
	vector<int> b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}
	cout << result << '\n';
	return 0;
}