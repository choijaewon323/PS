#include <iostream>
using namespace std;

long long dp[101][10];
int n;

long long func(int length, int num) {
	if (dp[length][num] != 0)
	{
		return dp[length][num];
	}
	if (length == n)
	{
		return 1;
	}
	if (num == 0)
	{
		return dp[length][num] = func(length + 1, num + 1) % 1000000000;
	}
	if (num == 9)
	{
		return dp[length][num] = func(length + 1, num - 1) % 1000000000;
	}
	return dp[length][num] = (func(length + 1, num + 1) + func(length + 1, num - 1)) % 1000000000;
}

int main() {
	cin >> n;

	cout << (func(1, 1) + func(1, 2) + func(1, 3) + func(1, 4) + func(1, 5) + func(1, 6) + func(1, 7) + func(1, 8) + func(1, 9)) % 1000000000 << '\n';

	return 0;
}