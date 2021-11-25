#include <iostream>
#include <algorithm>
using namespace std;
int triangle[501][501];
int dp[501][501];
int n;
int func(int y, int x) {
	if (y == n)
	{
		return triangle[y][x];
	}
	if (dp[y][x] != 0)
	{
		return dp[y][x];
	}
	int res1 = triangle[y][x] + func(y + 1, x);
	int res2 = triangle[y][x] + func(y + 1, x + 1);
	return dp[y][x] = max(res1, res2);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}
	cout << func(1, 1) << '\n';
	return 0;
}