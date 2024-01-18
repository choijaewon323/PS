#include <iostream>
#include <queue>

using namespace std;

#define MAX 100000

int N;
int cards[MAX];

int solve() {
	priority_queue<int, vector<int>, greater<int>> minPQ;

	for (int i = 0; i < N; i++) {
		minPQ.push(cards[i]);
	}

	int result = 0;
	while (minPQ.size() > 1) {
		int a = minPQ.top();
		minPQ.pop();
		int b = minPQ.top();
		minPQ.pop();

		result += (a + b);

		minPQ.push(a + b);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	int answer = solve();

	cout << answer << '\n';

	return 0;
}