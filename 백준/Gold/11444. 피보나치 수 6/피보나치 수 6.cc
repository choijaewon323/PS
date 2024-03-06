#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
#define MOD 1000000007

map<LL, vector<vector<LL>>> dp;

vector<vector<LL>> matrixMul(vector<vector<LL>> a, vector<vector<LL>> b) {
	vector<vector<LL>> result(2, vector<LL>(2, 0));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] += (a[i][k] * b[k][j]) % MOD;
				result[i][j] %= MOD;
			}
		}
	}

	return result;
}

vector<vector<LL>> fibonacci(vector<vector<LL>> matrix, LL n) {
	if (n == 1) {
		return matrix;
	}

	if (dp.find(n) != dp.end()) {
		return dp[n];
	}

	if (n % 2 == 0) {
		return dp[n] = matrixMul(fibonacci(matrix, n / 2), fibonacci(matrix, n / 2));
	} else {
		return dp[n] = matrixMul(fibonacci(matrix, n - 1), matrix);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	LL n;
	cin >> n;
	vector<vector<LL>> matrix = {
		{1, 1},
		{1, 0}
	};

	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if (n == 2) {
		cout << 1 << '\n';
		return 0;
	}

	vector<vector<LL>> result = fibonacci(matrix, n);
	cout << result[1][0] << '\n';

	return 0;
}