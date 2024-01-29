#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

int n;

int solve(const int num)
{
	if (num == 0)
	{
		return 1;
	}

	int res1 = 0;
	if (num - 3 >= 0)
	{
		res1 = solve(num - 3);
	}

	int res2 = 0;
	if (num - 2 >= 0)
	{
		res2 = solve(num - 2);
	}
	
	int res3 = 0;
	if (num - 1 >= 0)
	{
		res3 = solve(num - 1);
	}

	return res1 + res2 + res3;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test< T; test++)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}

	return 0;
}