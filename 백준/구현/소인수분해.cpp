#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	while (n >= 2)
	{
		for (int i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				cout << i << '\n';
				n = n / i;
				break;
			}
		}
	}

	return 0;
}