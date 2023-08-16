#include <iostream>

using namespace std;

#define CITYMAX 100000

int city[CITYMAX];
int roadLength[CITYMAX];
int cost[CITYMAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int length;

		cin >> length;
		roadLength[i] = length;
	}

	roadLength[N - 1] = 0;
	for (int i = 0; i < N; i++) {
		int c;

		cin >> c;

		if (i == N - 1) {
			cost[i] = 1000000001;
			continue;
		}
		cost[i] = c;
	}

	int index = 0;

	int answer = 0;

	if (N == 2) {
		answer += roadLength[0] * cost[0];

		cout << answer << '\n';

		return 0;
	}

	while (index < N - 1) {
		int presentCost = cost[index];

		int cnt = 0;
		int next;
		for (next = index + 1; next < N; next++) {
			if (presentCost > cost[next]) {
				break;
			}
			else {
				cnt += roadLength[next - 1] * presentCost;
			}
		}

		if (cnt == 0) {
			answer += presentCost * roadLength[index];
			index++;
		}
		else {
			answer += cnt;
			index = next;
		}
	}

	cout << answer << '\n';

	return 0;
}