#include <iostream>
using namespace std;

int factorial(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int number;

	cin >> number;

	cout << factorial(number) << '\n';
	return 0;
}