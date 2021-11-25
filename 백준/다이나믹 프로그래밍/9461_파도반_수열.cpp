#include <iostream>
using namespace std;

long long dp[101];

long long p(int n) {
	if (n == 1 || n == 2 || n == 3)
	{
		return 1;
	}
	if (n == 4 || n == 5)
	{
		return 2;
	}
	if (dp[n] != 0)
	{
		return dp[n];
	}
	return dp[n] = p(n - 1) + p(n - 5);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << p(n) << '\n';
	}
	return 0;
}