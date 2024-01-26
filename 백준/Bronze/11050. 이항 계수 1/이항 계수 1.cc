#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solve(const int N, const int K)
{
	if (K == 0 || N == K)
	{
		return 1;
	}

	if (K == 1)
	{
		return N;
	}

	return solve(N - 1, K) + solve(N - 1, K - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	cout << solve(N, K) << '\n';
	
	return 0;
}