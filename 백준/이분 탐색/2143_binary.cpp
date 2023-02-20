#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1001];
int b[1001];
vector<int> subSum;
int t, n, m;
long long result;

void input()
{
	cin >> t;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}
}

void solution()
{
	// a ¹è¿­
	for (int i = 1; i <= n; i++)
	{
		int acc = 0;
		for (int j = i; j <= n; j++)
		{
			acc += a[j];
			subSum.push_back(acc);
		}
	}

	sort(subSum.begin(), subSum.end());

	for (int i = 1; i <= m; i++)
	{
		int acc = 0;
		for (int j = i; j <= m; j++)
		{
			acc += b[j];
			long long start = lower_bound(subSum.begin(), subSum.end(), t - acc) - subSum.begin();
			long long end = upper_bound(subSum.begin(), subSum.end(), t - acc) - subSum.begin();

			result += end - start;
		}
	}

	cout << result << '\n';
}

int main()
{
	input();
	solution();

	return 0;
}