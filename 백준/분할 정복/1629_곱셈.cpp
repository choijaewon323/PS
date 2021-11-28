#include <iostream>
using namespace std;
int a, b, c;
unsigned long long func(int power)
{
	if (power == 1)
	{
		return a;
	}
	if (power % 2 == 1)
	{
		return (func(power - 1) * a) % c;
	}
	else
	{
		return (func(power / 2) * func(power / 2)) % c;
	}
}
int main()
{
	cin >> a >> b >> c;
	cout << func(b) % c << '\n';
	return 0;
}