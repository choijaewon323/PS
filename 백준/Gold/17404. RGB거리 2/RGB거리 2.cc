#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 1000
#define RED 0
#define GREEN 1
#define BLUE 2

int N;
int cost[MAX + 1][3];
int dpRed[MAX + 1][3]; // dp[i][j] : i번 집을 j로 칠할수 있는 경우의 최소 비용
int dpBlue[MAX + 1][3];
int dpGreen[MAX + 1][3];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
}

int solve() {
	dpRed[1][RED] = cost[1][RED];
	dpBlue[1][BLUE] = cost[1][BLUE];
	dpGreen[1][GREEN] = cost[1][GREEN];

	for (int i = 2; i <= N; i++) {
		if (i == 2) {
			dpRed[i][BLUE] = dpRed[1][RED] + cost[i][BLUE];
			dpRed[i][GREEN] = dpRed[1][RED] + cost[i][GREEN];

			dpGreen[i][BLUE] = dpGreen[1][GREEN] + cost[i][BLUE];
			dpGreen[i][RED] = dpGreen[1][GREEN] + cost[i][RED];

			dpBlue[i][RED] = dpBlue[1][BLUE] + cost[i][RED];
			dpBlue[i][GREEN] = dpBlue[1][BLUE] + cost[i][GREEN];
		} else if (i == N) {
			if (dpRed[i - 1][RED] != 0) {
				dpRed[i][GREEN] = min(dpRed[i - 1][BLUE], dpRed[i - 1][RED]) + cost[i][GREEN];
				dpRed[i][BLUE] = min(dpRed[i - 1][RED], dpRed[i - 1][GREEN]) + cost[i][BLUE];
			} else {
				dpRed[i][GREEN] = dpRed[i - 1][BLUE] + cost[i][GREEN];
				dpRed[i][BLUE] = dpRed[i - 1][GREEN] + cost[i][BLUE];
			}

			if (dpGreen[i - 1][GREEN] != 0) {
				dpGreen[i][RED] = min(dpGreen[i - 1][BLUE], dpGreen[i - 1][GREEN]) + cost[i][RED];
				dpGreen[i][BLUE] = min(dpGreen[i - 1][RED], dpGreen[i - 1][GREEN]) + cost[i][BLUE];
			} else {
				dpGreen[i][RED] = dpGreen[i - 1][BLUE] + cost[i][RED];
				dpGreen[i][BLUE] = dpGreen[i - 1][RED] + cost[i][BLUE];
			}

			if (dpBlue[i - 1][BLUE] != 0) {
				dpBlue[i][RED] = min(dpBlue[i - 1][BLUE], dpBlue[i - 1][GREEN]) + cost[i][RED];
				dpBlue[i][GREEN] = min(dpBlue[i - 1][BLUE], dpBlue[i - 1][RED]) + cost[i][GREEN];
			} else {
				dpBlue[i][RED] = dpBlue[i - 1][GREEN] + cost[i][RED];
				dpBlue[i][GREEN] = dpBlue[i - 1][RED] + cost[i][GREEN];
			}
		} else {
			dpRed[i][RED] = min(dpRed[i - 1][BLUE], dpRed[i - 1][GREEN]) + cost[i][RED];
			if (dpRed[i - 1][RED] != 0) {
				dpRed[i][GREEN] = min(dpRed[i - 1][BLUE], dpRed[i - 1][RED]) + cost[i][GREEN];
				dpRed[i][BLUE] = min(dpRed[i - 1][RED], dpRed[i - 1][GREEN]) + cost[i][BLUE];
			} else {
				dpRed[i][GREEN] = dpRed[i - 1][BLUE] + cost[i][GREEN];
				dpRed[i][BLUE] = dpRed[i - 1][GREEN] + cost[i][BLUE];
			}
		
			if (dpGreen[i - 1][GREEN] != 0) {
				dpGreen[i][RED] = min(dpGreen[i - 1][BLUE], dpGreen[i - 1][GREEN]) + cost[i][RED];
				dpGreen[i][BLUE] = min(dpGreen[i - 1][RED], dpGreen[i - 1][GREEN]) + cost[i][BLUE];
			} else {
				dpGreen[i][RED] = dpGreen[i - 1][BLUE]+ cost[i][RED];
				dpGreen[i][BLUE] = dpGreen[i - 1][RED] + cost[i][BLUE];
			}
			dpGreen[i][GREEN] = min(dpGreen[i - 1][BLUE], dpGreen[i - 1][RED]) + cost[i][GREEN];
			
			if (dpBlue[i - 1][BLUE] != 0) {
				dpBlue[i][RED] = min(dpBlue[i - 1][BLUE], dpBlue[i - 1][GREEN]) + cost[i][RED];
				dpBlue[i][GREEN] = min(dpBlue[i - 1][BLUE], dpBlue[i - 1][RED]) + cost[i][GREEN];
			} else {
				dpBlue[i][RED] = dpBlue[i - 1][GREEN] + cost[i][RED];
				dpBlue[i][GREEN] = dpBlue[i - 1][RED] + cost[i][GREEN];
			}
			dpBlue[i][BLUE] = min(dpBlue[i - 1][RED], dpBlue[i - 1][GREEN]) + cost[i][BLUE];
		}
	}

	return min(min(dpRed[N][GREEN], dpRed[N][BLUE]), min(min(dpBlue[N][GREEN], dpBlue[N][RED]), min(dpGreen[N][RED], dpGreen[N][BLUE])));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve() << '\n';

	return 0;
}