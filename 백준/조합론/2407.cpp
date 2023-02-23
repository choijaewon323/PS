#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define ll __uint128_t

int n, m;
ll dp[101][101];

ll func(int num, int k)
{
	if (k == 0 || k == num)
	{
		return 1;
	}

	if (dp[num][k] != 0)
	{
		return dp[num][k];
	}

	return dp[num][k] = func(num - 1, k) + func(num - 1, k - 1);
}

void input()
{
	cin >> n >> m;

	ll r = func(n, m);

	string result = "";
	string f = to_string((long long)(r / (ll)pow(10, 15)));
	string s = to_string((long long)(r % (ll)pow(10, 15)));

	if (f == "0")
	{
		result = s;
	}
	else
	{
		result = f + s;
	}

	cout << result << '\n';
}

int main()
{
	input();

	return 0;
}