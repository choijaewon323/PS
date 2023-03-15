#include <iostream>
#include <algorithm>
using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
	if (a < b)
	{
		swap(a, b);
	}

	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int64_t a, b;

	cin >> a >> b;

	int64_t result = gcd(a, b);

	for (int i = 0; i < result; i++)
	{
		cout << "1";
	}
	cout << '\n';

	return 0;
}