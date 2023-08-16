#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector<int> rope;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int maxWeight;

		cin >> maxWeight;
		rope.push_back(maxWeight);
	}

	sort(rope.begin(), rope.end(), greater<int>());

	int answer = -1;
	for (int i = 0; i < rope.size(); i++) {
		int k = i + 1;
		int weight = rope[i] * k;

		answer = max(answer, weight);
	}

	cout << answer << '\n';

	return 0;
}