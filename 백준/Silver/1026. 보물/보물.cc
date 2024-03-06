#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	vector<int> a;
	vector<int> b;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += a[i] * b[i];
	}
	cout << answer << '\n';

	return 0;
}