#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll mod = 1000000007ll;

vector<vector<ll>> matMul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
	vector<vector<ll>> result = { {0,0},{0,0} };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] %= mod;
			}
		}
	}

	return result;
}

vector<vector<ll>> fib(ll n)
{
	if (n == 1)
	{
		vector<vector<ll>> result = { { 1,1 }, { 1,0 } };
		return result;
	}
	if (n % 2 == 1)
	{
		vector<vector<ll>> a = { {1,1},{1,0} };
		vector<vector<ll>> b = fib(n - 1);
		vector<vector<ll>> result;
		result = matMul(a, b);
		return result;
	}
	else
	{
		vector<vector<ll>> a = fib(n / 2);
		vector<vector<ll>> b = a;
		vector<vector<ll>> result;
		result = matMul(a, b);
		return result;
	}
}

int main()
{
	ll n;
	cin >> n;

	if (n == 0)
	{
		cout << 0 << '\n';
	}
	else if (n == 1)
	{
		cout << 1 << '\n';
	}
	else if (n == 2)
	{
		cout << 1 << '\n';
	}
	else if (n == 3)
	{
		cout << 2 << '\n';
	}
	else
	{
		vector<vector<ll>> result;
		result = fib(n - 1);
		cout << result[0][0] % mod << '\n';
	}

	return 0;
}