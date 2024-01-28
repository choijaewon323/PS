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
#include <cmath>

using namespace std;

#define MAX 41

pair<int, int> dp[MAX];

pair<int, int> fibonacci(int n)
{
	if (n == 0)
	{
		return { 1, 0 };
	}
	else if (n == 1)
	{
		return { 0, 1 };
	}
	else if (dp[n].first != -1 && dp[n].second != -1)
	{
		return dp[n];
	}
	else
	{
		pair<int, int> res1 = fibonacci(n - 1);
		pair<int, int> res2 = fibonacci(n - 2);
		return dp[n] = { res1.first + res2.first, res1.second + res2.second };
	}
}

void init()
{
	for (int i = 0; i < 41; i++)
	{
		dp[i] = { -1, -1 };
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		init();
		int N;
		cin >> N;
		
		pair<int, int> ans = fibonacci(N);
		cout << ans.first << " " << ans.second << '\n';
	}

	return 0;
}