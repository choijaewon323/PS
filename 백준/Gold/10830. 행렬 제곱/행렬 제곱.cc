#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

typedef long long LL;

int N;
LL B;

map<LL, vector<vector<int>>> dp;

vector<vector<int>> matrixMul(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> result(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result[i][j] += (a[i][k] * b[k][j]) % 1000;
				result[i][j] %= 1000;
			}
		}
	}
	return result;
}

vector<vector<int>> solve(vector<vector<int>> matrix, LL up) {
	if (up == 1) {
		return matrix;
	}

	if (dp.find(up) != dp.end()) {
		return dp[up];
	}

	if (up % 2 == 0) {
		return dp[up] = matrixMul(solve(matrix, up / 2), solve(matrix, up / 2));
	} else {
		return dp[up] = matrixMul(solve(matrix, up - 1), matrix);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> B;
	vector<vector<int>> matrix(N, vector<int>(N, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
			matrix[y][x] %= 1000;
		}
	}

	vector<vector<int>> result = solve(matrix, B);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << result[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}