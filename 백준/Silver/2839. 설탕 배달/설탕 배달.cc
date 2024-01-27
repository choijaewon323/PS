#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>

using namespace std;

#define INF 100000000

#define MAX 5000

int dp[MAX + 1];

int solve(const int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (num < 0)
	{
		return INF;
	}

	if (dp[num] != 0)
	{
		return dp[num];
	}

	const int three = solve(num - 3) + 1;
	const int five = solve(num - 5) + 1;
	
	return dp[num] = min(three, five);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	const int answer = solve(N);

	if (answer >= INF)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << answer << '\n';
	}

	return 0;
}