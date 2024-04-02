#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 15

int N;
int T[MAX];
int P[MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
}

int solve(int day) {
	if (day == N) {
		return 0;
	}

	int result = 0;

	// jump
	if (day + T[day] <= N) {
		result = max(solve(day + T[day]) + P[day], result);
	}

	// no jump
	result = max(solve(day + 1), result);

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve(0) << '\n';
	
	return 0;
}