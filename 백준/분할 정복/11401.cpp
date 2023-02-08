#include <iostream>
using namespace std;

typedef long long ll;

ll mod = 1000000007ll;

ll power(ll val, ll p)
{
	if (p == 0)
	{
		return 1;
	}
	if (p == 1)
	{
		return val % mod;
	}
	if (p % 2 == 1)
	{
		return (val * power(val, p - 1)) % mod;
	}
	else
	{
		ll res = power(val, p / 2) % mod;
		return res * res % mod;
	}
}

int main()
{
	int n, k;
	ll a, b, c;
	ll val;
	cin >> n >> k;

	a = 1; b = 1; c = 1;
	for (int i = 1; i <= n; i++)
	{
		a *= i;
		a %= mod;
	}

	for (int i = 1; i <= k; i++)
	{
		b *= i;
		b %= mod;
	}

	for (int i = 1; i <= n - k; i++)
	{
		c *= i;
		c %= mod;
	}

	val = b * c % mod;

	val = power(val, mod - 2) % mod;

	val *= a;
	val %= mod;

	cout << val << '\n';

	return 0;
}