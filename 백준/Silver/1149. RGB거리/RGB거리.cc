#include <iostream>
#include <algorithm>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2
#define HOUSE_MAX 1000
#define NUMBER_OF_COLOR 3
#define INF 1000000000

int N;
int cost[HOUSE_MAX][NUMBER_OF_COLOR];
int dp[NUMBER_OF_COLOR][HOUSE_MAX];

void input() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < NUMBER_OF_COLOR; j++) {
			int temp;
			cin >> temp;

			cost[i][j] = temp;
		}
	}
}

bool isLastHouse(const int index) {
	return index == N - 1;
}

int solve(const int previousColor, const int houseIndex) {
	if (houseIndex == N) {
		return 0;
	}

	if (dp[previousColor][houseIndex] != 0) {
		return dp[previousColor][houseIndex];
	}

	int result = INF;
	for (int color = 0; color < NUMBER_OF_COLOR; color++) {
		if (color == previousColor) {
			continue;
		}

		result = min(result, solve(color, houseIndex + 1) + cost[houseIndex][color]);
	}

	return dp[previousColor][houseIndex] = result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	int answer = INF;
	for (int color = 0; color < NUMBER_OF_COLOR; color++) {
		answer = min(answer, solve(color, 1) + cost[0][color]);
	}
	cout << answer << '\n';

	return 0;
}