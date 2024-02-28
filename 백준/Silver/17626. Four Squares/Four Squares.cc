#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 50000

vector<int> squares;
int dp[MAX + 1];

void preCalculate()
{
	for (int i = 1; i <= 223; i++)
	{
		squares.push_back(i * i);
	}
	reverse(squares.begin(), squares.end());
}

int solve(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (dp[num] != 0)
	{
		return dp[num];
	}
	int result = MAX;
	for (int square : squares)
	{
		if (num >= square)
		{
			result = min(result, solve(num - square) + 1);
		}
	}
	return dp[num] = result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	preCalculate();
	int n;
	cin >> n;
	cout << solve(n) << '\n';
	return 0;
}