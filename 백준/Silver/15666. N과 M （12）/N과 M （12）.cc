#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

int N, M;
vector<int> input;
bool isUsed[10001];

void solve(vector<int> &numbers, int prev) {
	if (numbers.size() == M) {
		for (int number : numbers) {
			cout << number << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = prev; i < N; i++) {
		numbers.push_back(input[i]);
		solve(numbers, i);
		numbers.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (isUsed[temp]) {
			cnt++;
			continue;
		}

		isUsed[temp] = true;
		input.push_back(temp);
	}

	N -= cnt;
	sort(input.begin(), input.end());
	vector<int> numbers;
	solve(numbers, 0);

	return 0;
}