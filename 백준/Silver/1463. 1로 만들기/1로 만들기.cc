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

#define MAX 1000000
#define INF 100000000

typedef long long ll;

ll dp[MAX + 1];

ll solve(const int N)
{
	if (N == 1)
	{
		return 0;
	}
	if (dp[N] != -1)
	{
		return dp[N];
	}

	ll res1 = INF;
	ll res2 = INF;
	if (N % 3 == 0)
	{
		res1 = solve(N / 3) + 1;
	}
	if (N % 2 == 0)
	{
		res2 = solve(N / 2) + 1;
	}
	ll res3 = solve(N - 1) + 1;

	return dp[N] = min(res1, min(res2, res3));
}

void init()
{
	for (int i = 0; i < MAX + 1; i++)
	{
		dp[i] = -1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	init();
	cout << solve(N) << '\n';

	return 0;
}