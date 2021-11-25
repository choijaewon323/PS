#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int func(int x) {
	if (x == 1)
	{
		return 0;
	}
	if (dp[x] != 0)
	{
		return dp[x];
	}
	if (x % 3 == 0 && x % 2 == 0)
	{
		return dp[x] = min(func(x / 3), min(func(x / 2), func(x - 1))) + 1;
	}
	if (x % 3 == 0)
	{
		return dp[x] = min(func(x / 3), func(x - 1)) + 1;
	}
	if (x % 2 == 0)
	{
		return dp[x] = min(func(x / 2), func(x - 1)) + 1;
	}
	return dp[x] = func(x - 1) + 1;
}

int main() {
	int n;
	
	cin >> n;

	cout << func(n) << '\n';

	return 0;
}