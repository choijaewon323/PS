#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
using namespace std;

/*
	일단 추와 동일한 건 당연히 가능

	dp[i] : i 무게의 구슬을 잴 수 있는지 여부 ->
		시도 x -> -1, 가능 -> 1, 불가능 -> 0

	
*/

int weightCnt;
int beadCnt;

#define WEIGHT_MAX 30

int weight[WEIGHT_MAX];
map<pair<int, int>, int> dp;

bool solve(int b, int index) {
	if (b == 0) {
		return true;
	}

	if (index == weightCnt) {
		return false;
	}

	if (dp[{b, index}] != 0) {
		if (dp[{b, index}] == 1) {
			return false;
		}

		return true;
	}
	
	int w = weight[index];
	
	// add to left
	if (solve(b + w, index + 1)) {
		dp[{b, index}] = 2;
		return true;
	}

	// add to right
	if (solve(b - w, index + 1)) {
		dp[{b, index}] = 2;
		return true;
	}

	// nothing
	if (solve(b, index + 1)) {
		dp[{b, index}] = 2;
		return true;
	}

	dp[{b, index}] = 1;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> weightCnt;
	for (int i = 0; i < weightCnt; i++) {
		cin >> weight[i];
	}

	cin >> beadCnt;
	for (int i = 0; i < beadCnt; i++) {
		int bead;
		cin >> bead;

		bool result = solve(bead, 0);

		if (result) {
			cout << "Y" << " ";
		} else {
			cout << "N" << " ";
		}
	}
	cout << '\n';

	return 0;
}