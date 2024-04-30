#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MOD 1000000000

/*
*	1 1 1 1 1 1 1 1 1 1
	0 1 2 3 4 5 6 7 8 9
*/

int N;
int dp[101][10][1024];

int solve(int index, int present, int flag) {
	if (dp[index][present][flag] != -1) {
		return dp[index][present][flag];
	}

	if (index == 0) { // initial
		int result = 0;
		
		for (int i = 1; i <= 9; i++) {
			int flag = 0;
			flag = flag | (1 << i);
			result += solve(1, i, flag);
			result %= MOD;
		}
		
		return result;
	} else if (index == N) {
		if (flag == 1023) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if (present == 0) {
			int nextFlag = flag;
			nextFlag |= (1 << 1);
			return dp[index][present][flag] = solve(index + 1, 1, nextFlag);
		} else if (present == 9) {
			int nextFlag = flag;
			nextFlag |= (1 << 8);
			return dp[index][present][flag] = solve(index + 1, 8, nextFlag);
		} else {
			int nextFlag = flag;
			nextFlag |= (1 << present - 1);
			int result = 0;
			result += solve(index + 1, present - 1, nextFlag);
			result %= MOD;

			nextFlag = flag;
			nextFlag |= (1 << present + 1);
			result += solve(index + 1, present + 1, nextFlag);
			result %= MOD;
			
			return dp[index][present][flag] = result;
		}
	}
}

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	init();
	int result = solve(0, 0, 0);

	cout << result << '\n';
	
	return 0;
}