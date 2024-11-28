#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input;
int N, C;

bool isPossible(int dist) {
	int present = input[0];
	int size = input.size();
	int cnt = 1;

	for (int i = 1; i < size; i++) {
		if (input[i] - present >= dist) {
			cnt++;
			present = input[i];
		}
	}

	if (cnt >= C) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	int left = 1;
	int right = 1000000000;
	int answer = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2;

		if (isPossible(mid)) {
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << answer << '\n';

	return 0;
}