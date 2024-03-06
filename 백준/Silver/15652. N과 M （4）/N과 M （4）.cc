#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

int N, M;

void solve(vector<int> &numbers, int prev) {
	if (numbers.size() == M) {
		for (int number : numbers) {
			cout << number << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = prev; i <= N; i++) {
		numbers.push_back(i);
		solve(numbers, i);
		numbers.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	vector<int> numbers;
	solve(numbers, 1);

	return 0;
}