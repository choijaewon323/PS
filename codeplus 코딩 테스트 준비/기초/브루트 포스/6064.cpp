#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	for (int test_case = 0; test_case < t; test_case++)
	{
		int m, n, x, y;
		int answer;
		bool flag = false;
		cin >> m >> n >> x >> y;

		int limit = lcm(m, n);

		for (int i = x; i <= limit; i += m)
		{
			int right;

			if (i % n == 0)
			{
				right = n;
			}
			else
			{
				right = i % n;
			}

			if (right == y)
			{
				flag = true;
				answer = i;
				break;
			}
		}

		if (flag)
		{
			cout << answer << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}

	return 0;
}