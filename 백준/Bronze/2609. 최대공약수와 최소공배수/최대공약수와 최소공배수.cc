#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
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
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << '\n';
	
	long long divA = a / gcd(a, b);
	long long divB = b / gcd(a, b);

	long long answer = gcd(a, b) * divA * divB;
	
	cout << answer << '\n';
	
	return 0;
}